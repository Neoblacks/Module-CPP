#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	if (this != &rhs) {
		this->_vec_data = rhs._vec_data;
		this->_vec_chunk_data = rhs._vec_chunk_data;
		this->_list_data = rhs._list_data;
		this->_list_chunk_data = rhs._list_chunk_data;
	}
	return *this;
}


void swap_chunk(int *chunk, std::size_t nb_elem_chunk) {
	if (chunk[0] > chunk[1]) {
		std::swap(chunk[0], chunk[1]);
	}
	if (nb_elem_chunk == 3 && chunk[1] > chunk[2]) {
		std::swap(chunk[1], chunk[2]);
	}
	if (nb_elem_chunk == 3 && chunk[0] > chunk[1]) {
		std::swap(chunk[0], chunk[1]);
	}
}

void copy_chunk_to_vec(int *chunk, std::size_t nb_elem_chunk, std::vector<int> &vec, std::size_t &chunk_size) {
	while (chunk_size < nb_elem_chunk) {
		vec.push_back(chunk[chunk_size]);
		chunk_size++;
	}
}

void recopy_chunk1_from_vec(int *chunk, std::size_t nb_elem_chunk, std::vector<int> &vec) {
	for (size_t k = 0; k < nb_elem_chunk; k++) {
		chunk[k] = vec[k];
	}
}

void recopy_chunk2_from_vec(int *chunk, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2, std::vector<int> &vec) {
	for (size_t j = 0; j < nb_elem_chunk2; j++) {
		chunk[j] = vec[j + nb_elem_chunk1];
	}
}


void PmergeMe::sortVector(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2) {
	std::size_t i = 0;
	std::size_t chunk1_size = 0;
	std::size_t chunk2_size = 0;
	std::vector<int> vec;

	if (nb_elem_chunk1 == 2 || nb_elem_chunk1 == 3)
		swap_chunk(chunk1, nb_elem_chunk1);
	if (nb_elem_chunk2 == 2 || nb_elem_chunk2 == 3)
		swap_chunk(chunk2, nb_elem_chunk2);
	while (i < nb_elem_chunk1 + nb_elem_chunk2) {
		if (chunk1_size == nb_elem_chunk1) {
			copy_chunk_to_vec(chunk2, nb_elem_chunk2, vec, chunk2_size);
			break;
		}
		if (chunk2_size == nb_elem_chunk2) {
			copy_chunk_to_vec(chunk1, nb_elem_chunk1, vec, chunk1_size);
			break;
		}
		if (chunk1[chunk1_size] < chunk2[chunk2_size]) {
			vec.push_back(chunk1[chunk1_size]);
			chunk1_size++;
			continue;
		}
		if (chunk1[chunk1_size] > chunk2[chunk2_size]) {
			vec.push_back(chunk2[chunk2_size]);
			chunk2_size++;
			continue;
		}
		i++;
	}
	recopy_chunk1_from_vec(chunk1, nb_elem_chunk1, vec);
	recopy_chunk2_from_vec(chunk2, nb_elem_chunk1, nb_elem_chunk2, vec);
}

bool PmergeMe::check_Vec_chunk() {
	for (size_t i = 1; i < _vec_chunk_data.size(); i++) {
		if (_vec_chunk_data[i] <= 2 || _vec_chunk_data[i] == 3) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void PmergeMe::create_chunk_Vec() {
	std::size_t nb = get_vec_size_data();
	std::size_t val_chunk1 = 0;
	std::size_t val_chunk2 = 0;
	if (nb % 2 == 0) {
		val_chunk1 = nb / 2;
		val_chunk2 = nb / 2;
	}
	else {
		val_chunk1 = nb / 2;
		val_chunk2 = (nb / 2) + 1;
	}
	std::cout << "val_chunk1: " << val_chunk1 << std::endl;
	std::cout << "val_chunk2: " << val_chunk2 << std::endl;
	_vec_chunk_data.insert(_vec_chunk_data.begin(), -1);
	_vec_chunk_data.insert(_vec_chunk_data.begin(), val_chunk1);
	_vec_chunk_data.insert(_vec_chunk_data.begin(), val_chunk2);
	_vec_chunk_data.insert(_vec_chunk_data.begin(), -1); //CHECK TO REMOVE THIS

	while (!check_Vec_chunk()) {
		std::vector<int> vec;
		bool find_marker = false;
		for (std::vector<int>::iterator it = _vec_chunk_data.begin(); it != _vec_chunk_data.end(); ++it) {
			if (*it == -1) {
				if (!find_marker) {
					find_marker = true;
				}
				else {
					break;
				}
			}
			else if (find_marker) {
				if (*it % 2 == 0) {
					vec.push_back(*it / 2);
					vec.push_back(*it / 2); //TODO DO ONE FUNCTION
				}
				else {
					vec.push_back(*it / 2 + 1);
					vec.push_back(*it / 2);
				}
			}
		}
		for (std::vector<int>::reverse_iterator rev_it = vec.rbegin(); rev_it != vec.rend(); ++rev_it) {
			_vec_chunk_data.insert(_vec_chunk_data.begin(), *rev_it);
		}
		_vec_chunk_data.insert(_vec_chunk_data.begin(), -1);
	}
}

void PmergeMe::check_sort_good() {
	for (size_t i = 1; i <= this->_vec_data.size() - 1; i++) {
		if (this->_vec_data[i - 1] == static_cast<int>(i)) {
			std::cout << "Error: " << this->_vec_data[i - 1] << " != " << i << std::endl;
			return;
		}
	}
	std::cout << "Sort is good" << std::endl;
}

void PmergeMe::start_work() {
	std::size_t index = 0;
	for (size_t i = 0; i < _vec_chunk_data.size(); i++) {
		if (_vec_chunk_data[i] == -1) {
			index = 0;
			continue;
		}
		else {
			sortVector(&this->_vec_data[index], &this->_vec_data[index + _vec_chunk_data[i]], _vec_chunk_data[i],
					   _vec_chunk_data[i + 1]);
			index += _vec_chunk_data[i] + _vec_chunk_data[i + 1];
			i++;
		}
	}
}

void PmergeMe::pushBackVector(int n) {
	this->_vec_data.push_back(n);
}

void PmergeMe::print_vec() {
	for (size_t i = 0; i < this->_vec_data.size(); i++) {
		std::cout << this->_vec_data[i] << " ";
	}
	std::cout << std::endl;
}



























// // void swap_chunk(int *chunk, std::size_t nb_elem_chunk) {
// // 	if (chunk[0] > chunk[1]) {
// // 		std::swap(chunk[0], chunk[1]);
// // 	}
// // 	if (nb_elem_chunk == 3 && chunk[1] > chunk[2]) {
// // 		std::swap(chunk[1], chunk[2]);
// // 	}
// // 	if (nb_elem_chunk == 3 && chunk[0] > chunk[1]) {
// // 		std::swap(chunk[0], chunk[1]);
// // 	}
// // }

// void copy_chunk_to_list(int *chunk, std::size_t nb_elem_chunk, std::list<int> &lst, std::size_t &chunk_size) {
// 	while (chunk_size < nb_elem_chunk) {
// 		lst.push_back(chunk[chunk_size]);
// 		chunk_size++;
// 	}
// }

// void recopy_chunk1_from_list(int *chunk, std::size_t nb_elem_chunk, std::list<int> &lst) {
// 	std::list<int>::iterator it = lst.begin();
// 	for (size_t k = 0; k < nb_elem_chunk; k++) {
// 		chunk[k] = *it;
// 		++it;
// 	}
// }

// void recopy_chunk2_from_list(int *chunk, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2, std::list<int> &lst) {
// 	std::list<int>::iterator it = lst.begin();
// 	std::advance(it, nb_elem_chunk1);
// 	for (size_t j = 0; j < nb_elem_chunk2; j++) {
// 		chunk[j] = *it;
// 		++it;
// 	}
// }


// void PmergeMe::sortList(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2) {
// 	std::size_t i = 0;
// 	std::size_t chunk1_size = 0;
// 	std::size_t chunk2_size = 0;
// 	std::list<int> lst;

// 	if (nb_elem_chunk1 == 2 || nb_elem_chunk1 == 3)
// 		swap_chunk(chunk1, nb_elem_chunk1);
// 	if (nb_elem_chunk2 == 2 || nb_elem_chunk2 == 3)
// 		swap_chunk(chunk2, nb_elem_chunk2);
// 	while (i < nb_elem_chunk1 + nb_elem_chunk2) {
// 		if (chunk1_size == nb_elem_chunk1) {
// 			copy_chunk_to_list(chunk2, nb_elem_chunk2, lst, chunk2_size);
// 			break;
// 		}
// 		if (chunk2_size == nb_elem_chunk2) {
// 			copy_chunk_to_list(chunk1, nb_elem_chunk1, lst, chunk1_size);
// 			break;
// 		}
// 		if (chunk1[chunk1_size] < chunk2[chunk2_size]) {
// 			lst.push_back(chunk1[chunk1_size]);
// 			chunk1_size++;
// 			continue;
// 		}
// 		if (chunk1[chunk1_size] > chunk2[chunk2_size]) {
// 			lst.push_back(chunk2[chunk2_size]);
// 			chunk2_size++;
// 			continue;
// 		}
// 		i++;
// 	}
// 	recopy_chunk1_from_list(chunk1, nb_elem_chunk1, lst);
// 	recopy_chunk2_from_list(chunk2, nb_elem_chunk1, nb_elem_chunk2, lst);
// }

// bool PmergeMe::check_List_chunk() {
// 	for (std::list<int>::iterator it = _list_chunk_data.begin(); it != _list_chunk_data.end(); ++it) {
// 		if (*it <=2 || *it == 3) {
// 			return true;
// 		}
// 		else {
// 			return false;
// 		}
// 	}
// 	return false;
// }

// void PmergeMe::create_chunk_List() {
// 	std::size_t nb = get_list_size_data();
// 	std::size_t val_chunk1 = 0;
// 	std::size_t val_chunk2 = 0;
// 	if (nb % 2 == 0) {
// 		val_chunk1 = nb / 2;
// 		val_chunk2 = nb / 2;
// 	}
// 	else {
// 		val_chunk1 = nb / 2;
// 		val_chunk2 = (nb / 2) + 1;
// 	}
// 	std::cout << "val_chunk1: " << val_chunk1 << std::endl;
// 	std::cout << "val_chunk2: " << val_chunk2 << std::endl;
// 	_list_chunk_data.push_front(-1);
// 	_list_chunk_data.push_front(val_chunk2);
// 	_list_chunk_data.push_front(val_chunk1);
// 	_list_chunk_data.push_front(-1); //Check to remove or reverse chunk1 and chunk2

// 	while (!check_Vec_chunk()) {
// 		std::list<int> lst;
// 		bool find_marker = false;
// 		for (std::list<int>::iterator it = _list_chunk_data.begin(); it != _list_chunk_data.end(); ++it) {
// 			if (*it == -1) {
// 				if (!find_marker) {
// 					find_marker = true;
// 				}
// 				else {
// 					break;
// 				}
// 			}
// 			else if (find_marker) {
// 				if (*it % 2 == 0) {
// 					lst.push_back(*it / 2);
// 					lst.push_back(*it / 2); //TODO DO ONE FUNCTION
// 				}
// 				else {
// 					lst.push_back(*it / 2 + 1);
// 					lst.push_back(*it / 2);
// 				}
// 			}
// 		}
// 		for (std::list<int>::reverse_iterator rev_it = lst.rbegin(); rev_it != lst.rend(); ++rev_it) {
// 			_list_chunk_data.push_front(*rev_it);
// 		}
// 		_list_chunk_data.push_front(-1);
// 	}
// }

// // void PmergeMe::check_sort_good() {
// // 	for (size_t i = 1; i <= this->_vec_data.size() - 1; i++) {
// // 		if (this->_vec_data[i - 1] == static_cast<int>(i)) {
// // 			std::cout << "Error: " << this->_vec_data[i - 1] << " != " << i << std::endl;
// // 			return;
// // 		}
// // 	}
// // 	std::cout << "Sort is good" << std::endl;
// // }

// // void PmergeMe::start_work_list() {
// // 	std::size_t index = 0;
// // 	std::list<int>::iterator it = _list_chunk_data.begin();
// // 	while (it != _list_chunk_data.end()) {
// // 		if (*it == -1)
// // 		{
// // 			index = 0;
// // 			++it;
// // 			continue;
// // 		}
// // 		else
// // 		{
// // 			// std::list<int>::iterator start_chunk1 = std::next(_list_data.begin(), index);
// // 			// std::list<int>::iterator start_chunk2 = std::next(_list_data.begin(), *it);
// // 			// sortList(&(*start_chunk1), &(*start_chunk2), *it, *(std::next(it, 1)));
// // 			// index += *it + *(std::next(it, 1));
// // 			// std::advance(it, 2);
// // 			std::list<int>::iterator chunk1_start = _list_data.begin();
// // 			for (std::size_t i = 0; i < index; ++i)
// // 			{
// // 				++chunk1_start;
// // 			}
// // 			std::list<int>::iterator chunk2_start = _list_data.begin();
// // 			for (std::size_t i = 0; i < *it; ++i)
// // 			{
// // 				++chunk2_start;
// // 			}
// // 			std::list<int>::iterator it_next = it;
// // 			++it_next;
// // 			sortList(&(*chunk1_start), &(*chunk2_start), *it, *it_next);
// // 			index += *it + *it_next;
// // 			++it;
// // 			++it;
// // 		}
// // 	}
// // }

// void PmergeMe::start_work_list() {
//     std::size_t index = 0;
//     std::list<int>::iterator it = _list_chunk_data.begin();
//     while (it != _list_chunk_data.end()) {
//         if (*it == -1) {
//             index = 0;
//             ++it;
//             continue;
//         } else {
//             std::list<int>::iterator chunk1_start = _list_data.begin();
//             for (std::size_t i = 0; i < index; ++i) {
//                 ++chunk1_start;
//             }
//             std::list<int>::iterator chunk2_start = chunk1_start;
//             for (std::size_t i = 0; i < static_cast<std::size_t>(*it); ++i) {
//                 ++chunk2_start;
//             }
//             std::list<int>::iterator it_next = it;
//             ++it_next;
//             sortList(&(*chunk1_start), &(*chunk2_start), static_cast<std::size_t>(*it), static_cast<std::size_t>(*it_next));
//             index += static_cast<std::size_t>(*it) + static_cast<std::size_t>(*it_next);
//             ++it; // Advance the iterator by 1
//             ++it; // Advance the iterator by 1 again (equivalent to std::advance(it, 2))
//         }
//     }
// }

// void PmergeMe::pushBackList(int n) {
// 	this->_list_data.push_back(n);
// }

// void PmergeMe::print_list(){
// 	for (std::list<int>::iterator it = _list_data.begin(); it != _list_data.end(); ++it) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }
















PmergeMe::~PmergeMe() {
}
