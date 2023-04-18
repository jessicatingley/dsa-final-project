#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <cassert>
#include "parallel_insertion_sort.h"
#include "insertion_sort.h"

int num_threads = std::thread::hardware_concurrency();


std::vector<std::vector<int>> separate_vector(std::vector<int>& items){
    int size_sub_vects = std::round((float)items.size() / num_threads);
    std::vector<std::vector<int>> separated_vec;
    for(auto i = 0; i < num_threads; i++){
        std::vector<int> temp_sub_vec;
        for(auto j = 0; j < size_sub_vects; j++){
            if(!items.empty()) {
                temp_sub_vec.push_back(items[items.size() - 1]);
                items.pop_back();
            }
        }
        if(!temp_sub_vec.empty()) separated_vec.push_back(temp_sub_vec);
    }
    if(!items.empty()) separated_vec.push_back(items);
    return separated_vec;
}

std::vector<int> merge_sorted(std::vector<std::vector<int>>& sorted_vecs){
    auto max = 0;
    int index;
    std::vector<int> final_vec;
    while(!sorted_vecs.empty()) {
        for (auto i = 0; i < sorted_vecs.size(); i++) {
            if (sorted_vecs[i][sorted_vecs[i].size() - 1] >= max) {
                max = sorted_vecs[i][sorted_vecs[i].size() - 1];
                index = i;
            }
        }
        final_vec.push_back(max);
        sorted_vecs[index].pop_back();
        if(sorted_vecs[index].empty())
            sorted_vecs.erase(sorted_vecs.begin() + index, sorted_vecs.begin() + index + 1);
        max = 0;
    }
    reverse(final_vec.begin(), final_vec.end());
    return final_vec;
}

void parallel_insertion_sort(std::vector<int>& items){
    if(items.size() == 0 || items.size() == 1) return;
    std::vector<std::vector<int>> to_sort = separate_vector(items);
    std::vector<std::thread> threads;
    for(int i = 0; i <= num_threads; i++) threads.push_back(std::thread(insertion_sort, ref(to_sort[i])));

    for(int i = 0; i <= num_threads; i++) threads[i].join();

    items = merge_sorted(to_sort);
}

void test_separate_vector(){
    std::vector<int> input = {3, 2, 6, 8, 3, 1, 5};
    std::vector<std::vector<int>> correct = {{5}, {1}, {3}, {8}, {6}, {2}, {3}};
    std::vector<std::vector<int>> output = separate_vector(input);
    assert(output == correct);

    input = {3, 2, 1, 5, 8, 9, 0, 4, 10, 15, 2, 7, 13, 1};
    correct = {{1, 13}, {7, 2}, {15, 10}, {4, 0}, {9, 8}, {5, 1}, {2, 3}};
    output = separate_vector(input);
    assert(output == correct);
}