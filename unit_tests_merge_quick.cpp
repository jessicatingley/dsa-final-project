#include <iostream>
#include <vector>
#include <cassert>
#include "merge_sort.h"
#include "quick_sort.h"

template <void (*sorting_func)(std::vector<int>&, int, int)>
void test_sort_one_element() {
    std::vector<int> input{1};
    std::vector<int> output{1};
    sorting_func(input, 0, input.size()-1);
    assert(input == output);
}

template <void (*sorting_func)(std::vector<int>&, int, int)>
void test_sort_zero_element() {
    std::vector<int> input{};
    std::vector<int> output{};
    sorting_func(input, 0, input.size()-1);
    assert(input == output);
}

template <void (*sorting_func)(std::vector<int>&, int, int)>
void test_sort_duplicate_element() {
    std::vector<int> input{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> output{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    sorting_func(input, 0, input.size()-1);
    assert(input == output);
}

template <void (*sorting_func)(std::vector<int>&, int, int)>
void test_sort_even_length() {
    std::vector<int> input{1, 6, 4, 2, 7, 8};
    std::vector<int> output{1, 2, 4, 6, 7, 8};
    sorting_func(input, 0, input.size()-1);
    assert(input == output);
}

template <void (*sorting_func)(std::vector<int>&, int, int)>
void test_sort_odd_length() {
    std::vector<int> input{7, 3, 4, 0, 1, 3, 9};
    std::vector<int> output{0, 1, 3, 3, 4, 7, 9};
    sorting_func(input, 0, input.size()-1);
    assert(input == output);
}

template <void (*sorting_func)(std::vector<int>&, int, int)>
void test_partially_sorted() {
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 3, 5, 1, 6, 2, 4, 5};
    std::vector<int> output{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 7, 8};
    sorting_func(input, 0, input.size()-1);
    assert(input == output);
}

template <void (*sorting_func)(std::vector<int>&, int, int)>
void test_sort_reversed() {
    std::vector<int> input{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> output{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sorting_func(input, 0, input.size()-1);
    assert(input == output);
}

template <void (*sorting_func)(std::vector<int>&, int, int)>
void test_all() {
    test_sort_zero_element<sorting_func>();
    test_sort_one_element<sorting_func>();
    test_sort_duplicate_element<sorting_func>();
    test_sort_even_length<sorting_func>();
    test_sort_odd_length<sorting_func>();
    test_partially_sorted<sorting_func>();
    test_sort_reversed<sorting_func>();
}

int main(){
    test_all<merge_sort>();
    std::cout << " Merge Sort Passed" << std::endl;

    test_all<quick_sort>();
    std::cout << "Quick Sort Passed" << std::endl;
}


