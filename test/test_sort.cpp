//
// Created by Dylan on 31/05/2016.
//

#include "gtest/gtest.h"
#include "sort.h"

using namespace std;

TEST(BubbleSortTest, BubbleSort) {
    vector<int> unsorted {4, 6, 1, 3, 9, 8, 2, 5, 10, 7};
    vector<int> sorted {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubble_sort(unsorted);
    ASSERT_EQ(sorted, unsorted);
}