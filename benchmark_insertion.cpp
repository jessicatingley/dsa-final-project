#include <iostream>
#include <vector>
#include <chrono>
#include "insertion_sort.h"

template <void (*sorting_func)(std::vector<int>&)>
void benchmark_sorted(const int num_elements){
    std::vector<int> test;
    auto start = 0;
    for(auto i = 0; i < num_elements; i++){
        test.push_back(start);
        start++;
    }
    auto start_time = std::chrono::steady_clock::now();
    sorting_func(test);
    auto finish = std::chrono::steady_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start_time).count();
    std::cout << "Runtime for sorted vector of " << num_elements << " elements: " << runtime << std::endl;
}

template <void (*sorting_func)(std::vector<int>&)>
void benchmark_random(int num_elements){
    std::vector<int> test;
    for(auto i = 0; i < num_elements; i++){
        test.push_back(std::rand());
    }

    auto start = std::chrono::steady_clock::now();
    sorting_func(test);
    auto finish = std::chrono::steady_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count();
    std::cout << "Runtime for random vector of " << num_elements << " elements: " << runtime << std::endl;
}

template <void (*sorting_func)(std::vector<int>&)>
void benchmark_reverse_sort(const int num_elements){
    std::vector<int> test;
    auto element = num_elements;
    for(auto i = 0; i < num_elements; i++){
        test.push_back(element);
        element--;
    }
    auto start = std::chrono::steady_clock::now();
    sorting_func(test);
    auto finish = std::chrono::steady_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count();
    std::cout << "Runtime for reverse sorted vector of " << num_elements << " elements: " << runtime << std::endl;
}

template <void (*sorting_func)(std::vector<int>&)>
void benchmark_partial_sort(int num_elements){
    std::vector<int> test;
    auto element = 0;
    for(auto i = 0; i < num_elements/2; i++){
        test.push_back(element);
        element++;
    }

    for(auto i = num_elements/2; i < num_elements; i++){
        test.push_back(std::rand());
    }

    auto start = std::chrono::steady_clock::now();
    sorting_func(test);
    auto finish = std::chrono::steady_clock::now();
    auto runtime = std::chrono::duration_cast<std::chrono::duration<double>>(finish-start).count();
    std::cout << "Runtime for partially sorted vector of " << num_elements << " elements: " << runtime << std::endl;
}

template <void (*sorting_func)(std::vector<int>&)>
void benchmark_all(int num_elements) {
    benchmark_sorted<sorting_func>(num_elements);
    benchmark_random<sorting_func>(num_elements);
    benchmark_reverse_sort<sorting_func>(num_elements);
    benchmark_partial_sort<sorting_func>(num_elements);
}

int main(){
    std::cout << "Insertion Sort:\n";
    benchmark_all<insertion_sort>(10000);
}