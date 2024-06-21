#include "PmergeMe.hpp"

void swap_chunk_list(int *chunk, std::size_t nb_elem_chunk)
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

void copy_chunk_to_list(int *chunk, std::size_t nb_elem_chunk, std::list<int> &lst, std::size_t &chunk_size)
{
	while (chunk_size < nb_elem_chunk)
	{
		lst.push_back(chunk[chunk_size]);
		chunk_size++;
	}
}

void recopy_chunk1_from_list(int *chunk, std::size_t nb_elem_chunk, std::list<int> &lst)
{
	std::list<int>::iterator it = lst.begin();
	for (std::size_t k = 0; k < nb_elem_chunk; k++)
	{
		chunk[k] = *it;
		++it;
	}
}

void recopy_chunk2_from_list(int *chunk, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2, std::list<int> &lst)
{
	std::list<int>::iterator it = lst.begin();
	std::advance(it, nb_elem_chunk1); // Advance to the start of chunk2
	for (std::size_t j = 0; j < nb_elem_chunk2; j++)
	{
		chunk[j] = *it;
		++it;
	}
}

void PmergeMe::sortList(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2)
{
	std::size_t i = 0;
	std::size_t chunk1_size = 0;
	std::size_t chunk2_size = 0;
	std::list<int> lst;

	//ICI C EST LA MERDE AVEC LES CHUNKS CONDITIONNAL JUMP OR MOVE
	// std::cout << "Chunk1: ";
	// for (std::size_t i = 0; i < nb_elem_chunk1; i++)
	// {
	// 	std::cout << chunk1[i] << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "Chunk2: ";
	// for (std::size_t i = 0; i < nb_elem_chunk2; i++)
	// {
	// 	std::cout << chunk2[i] << " ";
	// }
	// std::cout << std::endl;

	if (nb_elem_chunk1 == 2 || nb_elem_chunk1 == 3)
		swap_chunk_list(chunk1, nb_elem_chunk1);

	if (nb_elem_chunk2 == 2 || nb_elem_chunk2 == 3)
		swap_chunk_list(chunk2, nb_elem_chunk2);

	while (i < nb_elem_chunk1 + nb_elem_chunk2)
	{
		if (chunk1_size == nb_elem_chunk1)
		{
			copy_chunk_to_list(chunk2, nb_elem_chunk2, lst, chunk2_size);
			break;
		}
		if (chunk2_size == nb_elem_chunk2)
		{
			copy_chunk_to_list(chunk1, nb_elem_chunk1, lst, chunk1_size);
			break;
		}
		if (chunk1[chunk1_size] < chunk2[chunk2_size])
		{
			lst.push_back(chunk1[chunk1_size]);
			chunk1_size++;
			continue;
		}
		if (chunk1[chunk1_size] > chunk2[chunk2_size])
		{
			lst.push_back(chunk2[chunk2_size]);
			chunk2_size++;
			continue;
		}
		i++;
	}

	recopy_chunk1_from_list(chunk1, nb_elem_chunk1, lst);
	recopy_chunk2_from_list(chunk2, nb_elem_chunk1, nb_elem_chunk2, lst);
}

bool PmergeMe::check_List_chunk()
{
	for (std::list<int>::iterator it = _list_chunk_data.begin(); it != _list_chunk_data.end(); ++it)
	{
		if (*it <= 2 || *it == 3)
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

void PmergeMe::create_chunk_List()
{
	std::size_t nb = get_list_size_data();
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
	_list_chunk_data.push_front(-1);
	_list_chunk_data.push_front(val_chunk2);
	_list_chunk_data.push_front(val_chunk1);
	_list_chunk_data.push_front(-1);

	while (!check_Vec_chunk())
	{
		std::list<int> lst;
		bool find_marker = false;
		for (std::list<int>::iterator it = _list_chunk_data.begin(); it != _list_chunk_data.end(); ++it)
		{
			if (*it == -1)
			{
				if (!find_marker)
					find_marker = true;
				else
					break;
			}
			else if (find_marker)
			{
				if (*it % 2 == 0)
				{
					lst.push_back(*it / 2);
					lst.push_back(*it / 2); // TODO DO ONE FUNCTION
				}
				else
				{
					lst.push_back(*it / 2 + 1);
					lst.push_back(*it / 2);
				}
			}
		}
		for (std::list<int>::reverse_iterator rev_it = lst.rbegin(); rev_it != lst.rend(); ++rev_it)
			_list_chunk_data.push_front(*rev_it);
		_list_chunk_data.push_front(-1);
	}
}

void PmergeMe::start_work_list()
{
	std::size_t index = 0;
	std::list<int>::iterator it = _list_chunk_data.begin();
	while (it != _list_chunk_data.end())
	{
		if (*it == -1)
		{
			index = 0;
			++it;
			continue;
		}
		else
		{
			std::list<int>::iterator chunk1_start = _list_data.begin();
			for (std::size_t i = 0; i < index; ++i)
			{
				++chunk1_start;
			}
			std::list<int>::iterator chunk2_start = chunk1_start;
			for (std::size_t i = 0; i < static_cast<std::size_t>(*it); ++i)
			{
				++chunk2_start;
			}
			std::list<int>::iterator it_next = it;
			++it_next;

			//ICI TOUT VA BIEN
			// std::cout << "Chunk1: ";
			// for (std::size_t i = 0; i < static_cast<std::size_t>(*it); i++)
			// {
			// 	std::cout << *chunk1_start << " ";
			// 	++chunk1_start;
			// }
			// std::cout << std::endl;
			// std::cout << "Chunk2: ";
			// for (std::size_t i = 0; i < static_cast<std::size_t>(*it_next); i++)
			// {
			// 	std::cout << *chunk2_start << " ";
			// 	++chunk2_start;
			// }
			// std::cout << std::endl;

			sortList(&(*chunk1_start), &(*chunk2_start), static_cast<std::size_t>(*it), static_cast<std::size_t>(*it_next));
			index += static_cast<std::size_t>(*it) + static_cast<std::size_t>(*it_next);
			std::advance(it, 2);
		}
	}
}

void PmergeMe::pushBackList(int n)
{
	this->_list_data.push_back(n);
}

void PmergeMe::print_list()
{
	for (std::list<int>::iterator it = _list_data.begin(); it != _list_data.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
