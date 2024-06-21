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
#include <string>
#include <cctype>
#include <deque>

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
    //DEQUE

    void sortDeque(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2);
    bool check_Deque_chunk();
    void    create_chunk_Deque();
    std::size_t get_deque_size_data() const { return this->_deque_data.size(); }
    // void check_sort_good_deque();
    void start_work_deque();
    void print_deque();
    void pushBackDeque(int n);

    //LIST

    // void sortList(int *chunk1, int *chunk2, std::size_t nb_elem_chunk1, std::size_t nb_elem_chunk2);
    // bool check_List_chunk();
    // void    create_chunk_List();
    // std::size_t get_list_size_data() const { return this->_list_data.size(); }
    // void check_sort_good_list();
    // void start_work_list();
    // void print_list();
    // void pushBackList(int n);


private:
    std::vector<int> _vec_data;
    std::vector<int> _vec_chunk_data;

    std::deque<int> _deque_data;
    std::deque<int> _deque_chunk_data;

    // std::list<int> _list_data;
    // std::list<int> _list_chunk_data;

};
