#include "PmergeMe.hpp"

void insertionSortDeque(int *chunk, std::size_t nb_elem_chunk)
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

void swap_chunk_deque(int *chunk, std::size_t nb_elem_chunk)
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

void copy_chunk_to_deque(int *chunk, std::size_t nb_elem_chunk, std::deque<int> &deque, std::size_t &chunk_size)
{
	while (chunk_size < nb_elem_chunk)
	{
		deque.push_back(chunk[chunk_size]);
		chunk_size++;
	}
}

void recopy_chunk1_from_deque(int *chunk, std::size_t nb_elem_chunk, std::deque<int> &deque)
{
	for (size_t k = 0; k < nb_elem_chunk; k++)
	{
		chunk[k] = deque[k];
	}
}

void recopy_chunk2_from_deque(int *chunk, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2, std::deque<int> &deque)
{
	for (size_t j = 0; j < nb_elem_chunk2; j++)
	{
		chunk[j] = deque[j + nb_elem_chunk1];
	}
}

void merge_deque(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2)
{
	std::deque<int> deque;
	std::size_t i = 0, j = 0;

	while (i < nb_elem_chunk1 && j < nb_elem_chunk2)
	{
		if (chunk1[i] <= chunk2[j])
		{
			deque.push_back(chunk1[i]);
			++i;
		}
		else
		{
			deque.push_back(chunk2[j]);
			++j;
		}
	}

	while (i < nb_elem_chunk1)
	{
		deque.push_back(chunk1[i]);
		++i;
	}

	while (j < nb_elem_chunk2)
	{
		deque.push_back(chunk2[j]);
		++j;
	}
	recopy_chunk1_from_deque(chunk1, nb_elem_chunk1, deque);
	recopy_chunk2_from_deque(chunk2, nb_elem_chunk1, nb_elem_chunk2, deque);
}

void PmergeMe::sortDeque(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2)
{
	if (nb_elem_chunk1 == 2 || nb_elem_chunk1 == 3)
	{
		insertionSortDeque(chunk1, nb_elem_chunk1);
	}
	if (nb_elem_chunk2 == 2 || nb_elem_chunk2 == 3)
	{
		insertionSortDeque(chunk2, nb_elem_chunk2);
	}
	merge_deque(chunk1, chunk2, nb_elem_chunk1, nb_elem_chunk2);
}

bool PmergeMe::check_Deque_chunk()
{
	for (size_t i = 1; i < _deque_chunk_data.size(); i++)
	{
		if (_deque_chunk_data[i] <= 2 || _deque_chunk_data[i] == 3)
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

void PmergeMe::create_chunk_Deque()
{
	std::size_t nb = get_deque_size_data();
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
	_deque_chunk_data.insert(_deque_chunk_data.begin(), -1);
	_deque_chunk_data.insert(_deque_chunk_data.begin(), val_chunk1);
	_deque_chunk_data.insert(_deque_chunk_data.begin(), val_chunk2);
	_deque_chunk_data.insert(_deque_chunk_data.begin(), -1); // CHECK TO REMOVE THIS

	while (!check_Deque_chunk())
	{
		std::deque<int> deque;
		bool find_marker = false;
		for (std::deque<int>::iterator it = _deque_chunk_data.begin(); it != _deque_chunk_data.end(); ++it)
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
					deque.push_back(*it / 2);
					deque.push_back(*it / 2); // TODO DO ONE FUNCTION
				}
				else
				{
					deque.push_back(*it / 2 + 1);
					deque.push_back(*it / 2);
				}
			}
		}
		for (std::deque<int>::reverse_iterator rev_it = deque.rbegin(); rev_it != deque.rend(); ++rev_it)
		{
			_deque_chunk_data.insert(_deque_chunk_data.begin(), *rev_it);
		}
		_deque_chunk_data.insert(_deque_chunk_data.begin(), -1);
	}
}

// void PmergeMe::check_sort_good()
// {
// 	for (size_t i = 1; i <= this->_deque_data.size() - 1; i++)
// 	{
// 		if (this->_deque_data[i - 1] == static_cast<int>(i))
// 		{
// 			std::cout << "Error: " << this->_deque_data[i - 1] << " != " << i << std::endl;
// 			return;
// 		}
// 	}
// 	std::cout << "Sort is good" << std::endl;
// }

void PmergeMe::start_work_deque()
{
	std::size_t index = 0;
	for (size_t i = 0; i < _deque_chunk_data.size(); i++)
	{
		if (_deque_chunk_data[i] == -1)
		{
			index = 0;
			continue;
		}
		else
		{
			sortDeque(&this->_deque_data[index], &this->_deque_data[index + _deque_chunk_data[i]], _deque_chunk_data[i],
					   _deque_chunk_data[i + 1]);
			index += _deque_chunk_data[i] + _deque_chunk_data[i + 1];
			i++;
		}
	}
}

void PmergeMe::pushBackDeque(int n)
{
	this->_deque_data.push_back(n);
}

void PmergeMe::print_deque()
{
	for (size_t i = 0; i < this->_deque_data.size(); i++)
	{
		std::cout << this->_deque_data[i] << " ";
	}
	std::cout << std::endl;
}
