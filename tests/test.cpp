// Copyright 2021 byteihq <kotov038@gmail.com>

#include <sorts.h>
#include <gtest/gtest.h>
#include <vector>
#include <functional>
#include <deque>
#include <list>

TEST(Sorts, BubbleSort) {
    {
        std::vector<int> v1;
        auto v2 = v1;
        bubble_sort(v1.begin(), v1.end());
        EXPECT_EQ(v2, v1);
    }
    {
        std::vector<int> v1 = {-2, 0, -4, 12, 1, 3, 4};
        auto v2 = v1;
        std::sort(v2.begin(), v2.end());
        bubble_sort(v1.begin(), v1.end());
        EXPECT_EQ(v1, v2);
    }
    {
        std::vector<float> v1 = {0.1, -0.3, 0.123, 0.001, 1.23, -9.0};
        auto v2 = v1;
        std::sort(v2.begin(), v2.end(), std::greater<float>());
        bubble_sort(v1.begin(), v1.end(), std::greater<float>());
        EXPECT_EQ(v1, v2);
    }
    {
        std::vector<float> v1 = {0.1, -0.3, 0.123, 0.001, 1.23, -9.0};
        auto v2 = v1;
        std::sort(v2.begin() + 1, v2.end() - 3, std::less<float>());
        bubble_sort(v1.begin() + 1, v1.end() - 3, std::less<float>());
        EXPECT_EQ(v1, v2);
    }
    {
        std::list<int> l1 = {0, 1, 2, 3, 4};
        auto l2 = l1;
        l2.sort();
        bubble_sort(l1.begin(), l1.end());
        EXPECT_EQ(l1, l2);
    }
    {
        std::deque<double> d1 = {-1, 2, 3, -5, 67};
        auto d2 = d1;
        std::sort(d1.begin(), d1.end());
        bubble_sort(d2.begin(), d2.end());
        EXPECT_EQ(d1, d2);
    }
}

TEST(Sorts, QuickSort) {
    {
        std::vector<int> v1;
        auto v2 = v1;
        quick_sort(v1.begin(), v1.end());
        EXPECT_EQ(v2, v1);
    }
    {
        std::vector<int> v1 = {-2, 0, -4, 12, 1, 3, 4};
        auto v2 = v1;
        std::sort(v2.begin(), v2.end());
        quick_sort(v1.begin(), v1.end());
        EXPECT_EQ(v1, v2);
    }
    {
        std::vector<float> v1 = {0.1, -0.3, 0.123, 0.001, 1.23, -9.0};
        auto v2 = v1;
        std::sort(v2.begin(), v2.end(), std::greater<float>());
        quick_sort(v1.begin(), v1.end(), std::greater<float>());
        EXPECT_EQ(v1, v2);
    }
    {
        std::vector<float> v1 = {0.1, -0.3, 0.123, 0.001, 1.23, -9.0};
        auto v2 = v1;
        std::sort(v2.begin() + 1, v2.end() - 3, std::less<float>());
        quick_sort(v1.begin() + 1, v1.end() - 3, std::less<float>());
        EXPECT_EQ(v1, v2);
    }
    {
        std::list<int> l1 = {0, 1, 2, 3, 4};
        auto l2 = l1;
        l2.sort();
        quick_sort(l1.begin(), l1.end());
        EXPECT_EQ(l1, l2);
    }
    {
        std::deque<double> d1 = {-1, 2, 3, -5, 67};
        auto d2 = d1;
        std::sort(d1.begin(), d1.end());
        quick_sort(d2.begin(), d2.end());
        EXPECT_EQ(d1, d2);
    }
}

TEST(Sorts, MergeSort) {
    {
        std::vector<int> v1;
        auto v2 = v1;
        merge_sort(v1.begin(), v1.end(), v1.begin());
        EXPECT_EQ(v2, v1);
    }
    {
        std::vector<int> v1 = {-2, 0, -4, 12, 1, 3, 4};
        auto v2 = v1;
        std::sort(v2.begin(), v2.end());
        merge_sort(v1.begin(), v1.end(), v1.begin());
        EXPECT_EQ(v1, v2);
    }
    {
        std::vector<float> v1 = {0.1, -0.3, 0.123, 0.001, 1.23, -9.0};
        auto v2 = v1;
        std::sort(v2.begin(), v2.end());
        merge_sort(v1.begin(), v1.end(), v1.begin());
        EXPECT_EQ(v1, v2);
    }
}

TEST(Sorts, InsertionSort) {
    {
        std::vector<int> v1;
        auto v2 = v1;
        insertion_sort(v1.begin(), v1.end());
        EXPECT_EQ(v2, v1);
    }
    {
        std::vector<int> v1 = {-2, 0, -4, 12, 1, 3, 4};
        auto v2 = v1;
        std::sort(v2.begin(), v2.end());
        insertion_sort(v1.begin(), v1.end());
        EXPECT_EQ(v1, v2);
    }
    {
        std::vector<float> v1 = {0.1, -0.3, 0.123, 0.001, 1.23, -9.0};
        auto v2 = v1;
        std::sort(v2.begin(), v2.end());
        insertion_sort(v1.begin(), v1.end());
        EXPECT_EQ(v1, v2);
    }
    {
        std::vector<float> v1 = {0.1, -0.3, 0.123, 0.001, 1.23, -9.0};
        auto v2 = v1;
        std::sort(v2.begin() + 1, v2.end() - 3);
        insertion_sort(v1.begin() + 1, v1.end() - 3);
        EXPECT_EQ(v1, v2);
    }
    {
        std::deque<double> d1 = {-1, 2, 3, -5, 67};
        auto d2 = d1;
        std::sort(d1.begin(), d1.end());
        insertion_sort(d2.begin(), d2.end());
        EXPECT_EQ(d1, d2);
    }
}
