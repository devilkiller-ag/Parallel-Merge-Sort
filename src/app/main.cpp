#include <chrono>
#include <iostream>

#include "sorting/mergeSort.hpp"
#include "sorting/parallelMergeSort.hpp"


int main() {
    const int SIZE = 10000000;
    std::vector<int> nums1(SIZE);
    std::vector<int> nums2(SIZE);

    for(int i = 0; i < SIZE; i++) {
        nums1[i] = rand() % SIZE;
        nums2[i] = rand() % SIZE;
    }

    /** ---------------------------------------------------------------------------------------------------------------------------------- */

    MergeSort *mergesort = new MergeSort(&nums1);

    // std::cout << "Before sorting: " << std::endl;
    // mergesort->print_array();
    
    auto normal_merge_sort_start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto normal_merge_sort_end = std::chrono::high_resolution_clock::now();

    // std::cout << std::endl << "After sorting: " << std::endl;
    // mergesort->print_array();

    std::chrono::duration<double> normal_merge_sort_duration = normal_merge_sort_end - normal_merge_sort_start;
    std::cout << std::endl << "Normal Merge Sort algorithm time taken: " << normal_merge_sort_duration.count() << " seconds" << std::endl;


    /** ---------------------------------------------------------------------------------------------------------------------------------- */

    ParallelMergeSort *parallelmergesort = new ParallelMergeSort(&nums2);

    // std::cout << "Before sorting: " << std::endl;
    // parallelmergesort->print_array();
    
    auto parallel_merge_sort_start = std::chrono::high_resolution_clock::now();
    parallelmergesort->sort();
    auto parallel_merge_sort_end = std::chrono::high_resolution_clock::now();

    // std::cout << std::endl << "After sorting: " << std::endl;
    // parallelmergesort->print_array();

    std::chrono::duration<double> parallel_merge_sort_duration = parallel_merge_sort_end - parallel_merge_sort_start;
    std::cout << std::endl << "Parallel Merge Sort algorithm time taken: " << parallel_merge_sort_duration.count() << " seconds" << std::endl;

    return 0;
}