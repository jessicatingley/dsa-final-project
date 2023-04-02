#include <iostream>
#include <vector>
#include "insertion_sort.h"

void insertion_sort(std::vector<int>& items){
    const int size = items.size();
    for(auto curr_idx = 1; curr_idx < size; curr_idx++){
        auto compare_idx = curr_idx - 1;
        const auto curr_val = items[curr_idx];
        while(compare_idx >= 0 && items[compare_idx] > curr_val){
            items[compare_idx + 1] = items[compare_idx];
            compare_idx -= 1;
        }
        items[compare_idx + 1] = curr_val;
    }
}