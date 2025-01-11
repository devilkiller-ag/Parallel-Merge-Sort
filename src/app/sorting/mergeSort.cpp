#include <cstdlib>
#include <iostream>

#include "mergeSort.hpp"


MergeSort::MergeSort(std::vector<int> *nums) {
    this->nums = nums;
}


void MergeSort::sort() {
    if((*nums).size() == 0) {
        exit(1);
    }

    recursive_sort(0, (*nums).size());
}


void MergeSort::recursive_sort(int left, int right) {
    if(left >= right) {
        return;
    }

    // Step 1: Divide the array into two halves 
    int mid = left + (right-left) / 2;

    recursive_sort(left, mid);
    recursive_sort(mid+1, right);


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


void MergeSort::print_array() {
    for(int i = 0; i < (*nums).size(); i++) {
        std::cout << (*nums)[i] << " ";
    }

    std::cout << std::endl;
}


MergeSort::~MergeSort() {
    delete nums;
}
