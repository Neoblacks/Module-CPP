#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
#include <iterator>
#include <deque>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe &operator=(const PmergeMe& rhs);
    //VECTOR

    void sortVector(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2);
    bool check_Vec_chunk();
    void    create_chunk_Vec();
    std::size_t get_vec_size_data() const { return this->_vec_data.size(); }
    void check_sort_good();
    void start_work();
    void print_vec();
    void pushBackVector(int n);

    //LIST
private:
    std::vector<int> _vec_data;
    std::vector<int> _vec_chunk_data;

    std::list<int> _list_data;
    std::list<int> _list_chunk_data;
};