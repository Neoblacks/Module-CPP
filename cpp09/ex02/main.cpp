#include "PmergeMe.hpp"

bool DuplicateCheck(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		for (int j = i + 1; j < argc; j++) {
			if (std::atoi(argv[i]) == std::atoi(argv[j])) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char **argv) {
	if (argc <= 2) {
		std::cout << "Invalid input" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			if (std::isdigit(argv[i][j]) == 0) {
				std::cout << "Error in input, please enter only positive numbers" << std::endl;
				return 1;
			}
		}
	}
	if (DuplicateCheck(argc, argv) == 1) {
		std::cout << "Error in input, please enter only unique numbers" << std::endl;
		return 1;
	}

	//START OF THE PROGRAM

	PmergeMe sorting;
	for (int i = 1; i < argc; i++) {
		// sorting.pushBackVector(std::atoi(argv[i]));
		sorting.pushBackDeque(std::atoi(argv[i]));
	}
	// std::clock_t timeStartVec, timeEndVec;
	// double timeVec;
	// std::cout << "Before sort vec: ";
	// sorting.print_vec();
	// timeStartVec = std::clock();
	// sorting.create_chunk_Vec();
	// sorting.start_work();
	// timeEndVec = std::clock();
	// timeVec = (timeEndVec - timeStartVec) / (double) CLOCKS_PER_SEC;
	// std::cout << "After: ";
	// sorting.print_vec();
	// std::cout << "Time: " << std::fixed << std::setprecision(10) << timeVec << "s" << std::endl;





	std::clock_t timeStartDeque, timeEndDeque;
	double timeDeque;
	std::cout << "Before sort deque: ";
	sorting.print_deque();
	timeStartDeque = std::clock();
	sorting.create_chunk_Deque();
	sorting.start_work_deque();
	timeEndDeque = std::clock();
	timeDeque = (timeEndDeque - timeStartDeque) / (double) CLOCKS_PER_SEC;
	std::cout << "After: ";
	// sorting.print_deque();
	std::cout << "Time: " << std::fixed << std::setprecision(10) << timeDeque << "s" << std::endl;

}
