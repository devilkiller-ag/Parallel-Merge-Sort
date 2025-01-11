#ifndef MERGESORT_HPP
#define MERGESORT_HPP


#include <vector>


class MergeSort {
private:
    std::vector<int> *nums;

public:
    MergeSort(std::vector<int> *nums);
    void sort();
    void recursive_sort(int left, int right);
    void print_array();
    ~MergeSort();
};


#endif // MERGESORT_HPP