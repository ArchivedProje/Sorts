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

template<typename RandomIt>
std::vector<typename RandomIt::value_type>
merge(const RandomIt begin, const RandomIt mid, const RandomIt end) {
    std::vector<typename RandomIt::value_type> elements;
    RandomIt it_l(begin);
    RandomIt it_r(mid);
    const RandomIt it_mid(mid);
    const RandomIt it_end(end);
    while (it_l != it_mid && it_r != it_end) {
        elements.push_back((*it_l <=  *it_r) ? *it_l++ : *it_r++);
    }

    elements.insert(elements.end(), it_l, it_mid);
    elements.insert(elements.end(), it_r, it_end);

    return elements;
}

template<typename RandomIt>
void merge_sort(RandomIt begin, RandomIt end) {
    auto size = std::distance(begin, end);
    if (size < 2) return;

    auto middle = std::next(begin, size / 2);
    merge_sort(begin, middle);
    merge_sort(middle, end);

    auto &&res = merge(begin, middle, end);
    std::move(res.cbegin(), res.cend(), begin);
}

template<class RandomIt>
void insertion_sort(RandomIt begin, RandomIt end) {
    for (auto i = begin; i != end; ++i) {
        std::rotate(std::upper_bound(begin, i, *i), i, i + 1);
    }
}

#endif //SORTS_SORTS_H
