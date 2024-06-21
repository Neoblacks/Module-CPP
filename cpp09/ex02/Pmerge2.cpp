#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		// this->_vec_data = rhs._vec_data;
		// this->_vec_chunk_data = rhs._vec_chunk_data;
		// this->_list_data = rhs._list_data;
		// this->_list_chunk_data = rhs._list_chunk_data;
		this->_deque_data = rhs._deque_data;
		this->_deque_chunk_data = rhs._deque_chunk_data;
	}
	return *this;
}

void insertionSort(int *chunk, std::size_t nb_elem_chunk)
{
	for (std::size_t i = 1; i < nb_elem_chunk; ++i)
	{
		int key = chunk[i];
		int j = i - 1;

		while (j >= 0 && chunk[j] > key)
		{
			chunk[j + 1] = chunk[j];
			--j;
		}
		chunk[j + 1] = key;
	}
}

void swap_chunk(int *chunk, std::size_t nb_elem_chunk)
{
	if (chunk[0] > chunk[1])
	{
		std::swap(chunk[0], chunk[1]);
	}
	if (nb_elem_chunk == 3 && chunk[1] > chunk[2])
	{
		std::swap(chunk[1], chunk[2]);
	}
	if (nb_elem_chunk == 3 && chunk[0] > chunk[1])
	{
		std::swap(chunk[0], chunk[1]);
	}
}

void copy_chunk_to_vec(int *chunk, std::size_t nb_elem_chunk, std::vector<int> &vec, std::size_t &chunk_size)
{
	while (chunk_size < nb_elem_chunk)
	{
		vec.push_back(chunk[chunk_size]);
		chunk_size++;
	}
}

void recopy_chunk1_from_vec(int *chunk, std::size_t nb_elem_chunk, std::vector<int> &vec)
{
	for (size_t k = 0; k < nb_elem_chunk; k++)
	{
		chunk[k] = vec[k];
	}
}

void recopy_chunk2_from_vec(int *chunk, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2, std::vector<int> &vec)
{
	for (size_t j = 0; j < nb_elem_chunk2; j++)
	{
		chunk[j] = vec[j + nb_elem_chunk1];
	}
}

void merge(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2)
{
	std::vector<int> vec;
	std::size_t i = 0, j = 0;

	while (i < nb_elem_chunk1 && j < nb_elem_chunk2)
	{
		if (chunk1[i] <= chunk2[j])
		{
			vec.push_back(chunk1[i]);
			++i;
		}
		else
		{
			vec.push_back(chunk2[j]);
			++j;
		}
	}

	while (i < nb_elem_chunk1)
	{
		vec.push_back(chunk1[i]);
		++i;
	}

	while (j < nb_elem_chunk2)
	{
		vec.push_back(chunk2[j]);
		++j;
	}
	recopy_chunk1_from_vec(chunk1, nb_elem_chunk1, vec);
	recopy_chunk2_from_vec(chunk2, nb_elem_chunk1, nb_elem_chunk2, vec);
}

void PmergeMe::sortVector(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2)
{
	if (nb_elem_chunk1 == 2 || nb_elem_chunk1 == 3)
	{
		insertionSort(chunk1, nb_elem_chunk1);
	}
	if (nb_elem_chunk2 == 2 || nb_elem_chunk2 == 3)
	{
		insertionSort(chunk2, nb_elem_chunk2);
	}
	merge(chunk1, chunk2, nb_elem_chunk1, nb_elem_chunk2);
}

bool PmergeMe::check_Vec_chunk()
{
	for (size_t i = 1; i < _vec_chunk_data.size(); i++)
	{
		if (_vec_chunk_data[i] <= 2 || _vec_chunk_data[i] == 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void PmergeMe::create_chunk_Vec()
{
	std::size_t nb = get_vec_size_data();
	std::size_t val_chunk1 = 0;
	std::size_t val_chunk2 = 0;
	if (nb % 2 == 0)
	{
		val_chunk1 = nb / 2;
		val_chunk2 = nb / 2;
	}
	else
	{
		val_chunk1 = nb / 2;
		val_chunk2 = (nb / 2) + 1;
	}
	std::cout << "val_chunk1: " << val_chunk1 << std::endl;
	std::cout << "val_chunk2: " << val_chunk2 << std::endl;
	_vec_chunk_data.insert(_vec_chunk_data.begin(), -1);
	_vec_chunk_data.insert(_vec_chunk_data.begin(), val_chunk1);
	_vec_chunk_data.insert(_vec_chunk_data.begin(), val_chunk2);
	_vec_chunk_data.insert(_vec_chunk_data.begin(), -1); // CHECK TO REMOVE THIS

	while (!check_Vec_chunk())
	{
		std::vector<int> vec;
		bool find_marker = false;
		for (std::vector<int>::iterator it = _vec_chunk_data.begin(); it != _vec_chunk_data.end(); ++it)
		{
			if (*it == -1)
			{
				if (!find_marker)
				{
					find_marker = true;
				}
				else
				{
					break;
				}
			}
			else if (find_marker)
			{
				if (*it % 2 == 0)
				{
					vec.push_back(*it / 2);
					vec.push_back(*it / 2); // TODO DO ONE FUNCTION
				}
				else
				{
					vec.push_back(*it / 2 + 1);
					vec.push_back(*it / 2);
				}
			}
		}
		for (std::vector<int>::reverse_iterator rev_it = vec.rbegin(); rev_it != vec.rend(); ++rev_it)
		{
			_vec_chunk_data.insert(_vec_chunk_data.begin(), *rev_it);
		}
		_vec_chunk_data.insert(_vec_chunk_data.begin(), -1);
	}
}

void PmergeMe::check_sort_good()
{
	for (size_t i = 1; i <= this->_vec_data.size() - 1; i++)
	{
		if (this->_vec_data[i - 1] == static_cast<int>(i))
		{
			std::cout << "Error: " << this->_vec_data[i - 1] << " != " << i << std::endl;
			return;
		}
	}
	std::cout << "Sort is good" << std::endl;
}

void PmergeMe::start_work()
{
	std::size_t index = 0;
	for (size_t i = 0; i < _vec_chunk_data.size(); i++)
	{
		if (_vec_chunk_data[i] == -1)
		{
			index = 0;
			continue;
		}
		else
		{
			sortVector(&this->_vec_data[index], &this->_vec_data[index + _vec_chunk_data[i]], _vec_chunk_data[i],
					   _vec_chunk_data[i + 1]);
			index += _vec_chunk_data[i] + _vec_chunk_data[i + 1];
			i++;
		}
	}
}

void PmergeMe::pushBackVector(int n)
{
	this->_vec_data.push_back(n);
}

void PmergeMe::print_vec()
{
	for (size_t i = 0; i < this->_vec_data.size(); i++)
	{
		std::cout << this->_vec_data[i] << " ";
	}
	std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{
}
