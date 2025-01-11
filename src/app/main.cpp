#include <chrono>
#include <iostream>

#include "sorting/mergeSort.hpp"


int main() {
    const int SIZE = 1000;
    std::vector<int> nums(SIZE);


    for(int i = 0; i < SIZE; i++) {
        nums[i] = rand() % 1000;
    }

    MergeSort *mergesort = new MergeSort(&nums);

    // std::cout << "Before sorting: " << std::endl;
    // mergesort->print_array();
    
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();

    // std::cout << std::endl << "After sorting: " << std::endl;
    // mergesort->print_array();

    std::chrono::duration<double> duration = end - start;
    std::cout << std::endl << "Merge Sort algorithm time taken: " << duration.count() << " seconds" << std::endl;


    return 0;
}