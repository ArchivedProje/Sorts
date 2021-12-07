// Copyright 2021 byteihq <kotov038@gmail.com>

#ifndef SORTS_SORTS_H
#define SORTS_SORTS_H

#include <vector>
#include <functional>
#include <algorithm>

template<typename RandomIt, typename Compare = std::less<>>
void bubble_sort(RandomIt begin, RandomIt end, Compare cmp = Compare()) {
    if (std::distance(begin, end) <= 1) return;

    for (auto i = begin; i != std::prev(end); ++i) {
        for (auto j = std::next(i); j != end; ++j) {
            if (cmp(*j, *i)) {
                std::iter_swap(i, j);
            }
        }
    }
}

template<typename RandomIt, typename Compare = std::less<>>
void quick_sort(RandomIt begin, RandomIt end, Compare cmp = Compare()) {
    if (begin == end) return;
    auto pivot = *std::prev(end);
    auto first_it = std::partition(begin, end,
                                   [&pivot, &cmp](const auto &item) { return cmp(item, pivot); });
    auto second_it = std::partition(first_it, end,
                                    [&pivot, &cmp](const auto &item) { return !cmp(pivot, item); });
    quick_sort(begin, first_it, cmp);
    quick_sort(second_it, end, cmp);
}

template<typename RandomIt, typename Out, typename Compare = std::less<>>
Out merge(RandomIt first1, RandomIt last1, RandomIt first2, RandomIt last2, Out out,
          Compare cmp = Compare()) {
    while (first1 != last1 && first2 != last2) {
        if (cmp(*first2, *first1)) {
            *out = *first2;
            ++first2;
        } else {
            *out = *first1;
            ++first1;
        }
        ++out;
    }
    return std::copy(first2, last2, std::copy(first1, last1, out));
}

template<typename RandomIt, typename Out, typename Compare = std::less<>>
Out merge_sort(RandomIt begin, RandomIt end, Out out, Compare cmp = Compare()) {
    if (std::distance(end, begin) <= 1) return begin;

    std::vector elements(begin, end);
    auto elements_begin = elements.begin();
    auto elements_end = elements.end();
    auto middle = elements.size() / 2 + elements_begin;
    merge_sort(elements_begin, middle, out);
    merge_sort(middle, elements_end, out);
    out = merge(elements_begin, middle, middle, elements_end, begin, cmp);
    return out;
}

template<class RandomIt>
void insertion_sort(RandomIt begin, RandomIt end) {
    for (auto i = begin; i != end; ++i) {
        std::rotate(std::upper_bound(begin, i, *i), i, i+1);
    }
}

#endif //SORTS_SORTS_H
