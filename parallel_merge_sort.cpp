#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include "parallel_merge_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

/*------------------------------------------------------------------------------------
 * Function: parallel_merge_sort
 * Description:
 *
 * Input: Reference to the vector to be sorted (vector<int>&)
 * Output: None (void)
 * Process:
 ------------------------------------------------------------------------------------*/
void parallel_merge_sort_r(std::vector<int>& items, int low, int high){
    int midpoint = (low + high) / 2;
    if(high - low <= 5000){
        merge_sort(items, low, high);
        return;
    }
    std::thread thread1(parallel_merge_sort_r, ref(items), low, midpoint);
    parallel_merge_sort_r(items, midpoint + 1, high);
    thread1.join();
    merge(items, low, midpoint, high);
}

void parallel_merge_sort(std::vector<int>& items){
    parallel_merge_sort_r(items, 0, items.size() - 1);
}