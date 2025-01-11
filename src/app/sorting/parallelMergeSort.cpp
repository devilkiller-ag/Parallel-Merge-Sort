#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "parallelMergeSort.hpp"


ParallelMergeSort::ParallelMergeSort(std::vector<int> *nums) {
    this->nums = nums;
}


void ParallelMergeSort::sort() {
    if((*nums).size() == 0) {
        exit(1);
    }

    std::thread thread_1([this] {this->recursive_sort(0, (*nums).size());});
    thread_1.join();
}


void ParallelMergeSort::recursive_sort(int left, int right) {
    // Multithreading threshold
    const int THRESHOLD = 5000;

    if(right - left <= THRESHOLD) {
        std::sort((*nums).begin() + left, (*nums).begin() + right + 1);
        return;
    }

    // Base Case
    if(left >= right) {
        return;
    }

    // Step 1: Divide the array into two halves 
    int mid = left + (right-left) / 2;

    std::thread thread_1([this, left, mid] {this->recursive_sort(left, mid);});
    std::thread thread_2([this, mid, right] {this->recursive_sort(mid+1, right);});

    thread_1.join();
    thread_2.join();

    // Step 2: Merge the two halves
    std::vector<int> result;
    int i = left, j = mid+1;

    while(i <= mid && j <= right) {
        if((*nums)[i] < (*nums)[j]) {
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while(i <= mid) {
        result.push_back((*nums)[i]);
        i++;
    }

    while(j <= right) {
        result.push_back((*nums)[j]);
        j++;
    }

    
    // Step 3: Copy the result back to the original array
    for(int i = left; i <= right; i++) {
        (*nums)[i] = result[i-left];
    }

    return;
}


void ParallelMergeSort::print_array() {
    for(int i = 0; i < (*nums).size(); i++) {
        std::cout << (*nums)[i] << " ";
    }

    std::cout << std::endl;
}


ParallelMergeSort::~ParallelMergeSort() {
    delete nums;
}
