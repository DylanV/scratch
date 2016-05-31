//
// Created by Dylan on 31/05/2016.
//


#ifndef SCRATCH_SORT_H
#define SCRATCH_SORT_H

#include <vector>
using namespace std;

template <typename T>
void bubble_sort(vector<T> &unsorted) {
    bool has_swapped = true;
    while(has_swapped){
        has_swapped=false;
        for(int i=0; i<unsorted.size()-1; i++){
            if(unsorted[i] > unsorted[i+1]){
                T temp = unsorted[i];
                unsorted[i] = unsorted[i+1];
                unsorted[i+1] = temp;
                has_swapped = true;
            }
        }
    }
}

template <typename T>
void selection_sort(vector<T> &unsorted) {
    for(int i = 0; i<unsorted.size(); i++){ //Grow sorted sublist
        int min_index = i;
        //Find minimum in unsorted sublist
        for(int j = i+1; j<unsorted.size(); j++){
            if(unsorted[j] < unsorted[min_index]){
                min_index = j;
            }
        }
        //Swap minimum to top of sorted sublist
        if(min_index != i){
            T temp = unsorted[i];
            unsorted[i] = unsorted[min_index];
            unsorted[min_index] = temp;
        }
    }
}

template <typename T>
size_t partition(vector<T> &A, size_t lo, size_t hi) { //https://en.wikipedia.org/wiki/Quicksort
    T pivot = A[lo];
    size_t i = lo;
    size_t j = hi;
    while(true){
        while(A[i] < pivot){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }
        if(i >= j){
            return j;
        }
        //swap A[i] with A[j]
        T temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

template <typename T>
void quick_sort(vector<T> &A, size_t lo, size_t hi) { //https://en.wikipedia.org/wiki/Quicksort
    if(lo < hi){
        size_t p = partition(A, lo, hi);
        quick_sort(A, lo, p);
        quick_sort(A, p+1, hi);
    }
}

#endif //SCRATCH_SORT_H
