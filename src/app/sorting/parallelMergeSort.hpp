#ifndef PARALLELMERGESORT_HPP
#define PARALLELMERGESORT_HPP


#include <mutex>
#include <vector>
#include <thread>
#include <iostream>


class ParallelMergeSort {
private:
    std::vector<int> *nums;

public:
    ParallelMergeSort(std::vector<int> *nums);
    void sort();
    void recursive_sort(int left, int right);
    void print_array();
    ~ParallelMergeSort();
};


#endif // PARALLELMERGESORT_HPP