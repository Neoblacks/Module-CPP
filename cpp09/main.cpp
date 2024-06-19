#include "PmergeMe.hpp"

bool DuplicateCheck(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        for (int j = i + 1; j < argc; j++) {
            if (std::stoi(argv[i]) == std::stoi(argv[j])) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        std::cout << "Invalid inpu11111" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            if (std::isdigit(argv[i][j]) == 0)
            {
                std::cout << "Error in input, please enter only numbers" << std::endl;
                return 1;
            }
        }
    }

    if (DuplicateCheck(argc, argv) == 1)
    {
        std::cout << "Error in input, please enter only unique numbers" << std::endl;
        return 1;
    }

    PmergeMe sorting;
    for (int i = 1; i < argc; i++)
    {
        sorting.pushBackVector(std::atoi(argv[i]));
    }

    std::clock_t VectorStartPyra, VectorEndPyra, VectorStartSort, VectorEndSort;
    double durationPyra, durationSort, durationMerge;

    std::cout << "Before: ";
    sorting.print_vec();
    sorting.create_chunk_Vec();
    sorting.start_work();
    std::cout << "After: ";
    sorting.print_vec();
}