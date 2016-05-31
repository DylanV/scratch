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

#endif //SCRATCH_SORT_H
