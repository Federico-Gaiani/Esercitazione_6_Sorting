#pragma once

#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"

namespace SortLibrary {

TEST(TestSorting, TestBubbleSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    BubbleSort<int>(v);
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, BubbleSortVuoto)
{
    std::vector<int> v; // vettore vuoto
    BubbleSort<int>(v);
    EXPECT_TRUE(v.empty()); 
}

TEST(TestSorting, TestHeapSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    HeapSort<int>(v);
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, HeapSortVuoto)
{
    std::vector<int> v; // vettore vuoto
    HeapSort<int>(v);
    EXPECT_TRUE(v.empty()); 
}

TEST(TestSorting, TestMyHeapSort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    My_HeapSort<int>(v);
    std::vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, sortedV);
}

TEST(TestSorting, MyHeapSortVuoto)
{
    std::vector<int> v; // vettore vuoto
    My_HeapSort<int>(v);
    EXPECT_TRUE(v.empty()); 
}

}
