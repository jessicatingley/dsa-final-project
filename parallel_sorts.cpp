#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <algorithm>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "parallel_sorts.h"
#include "split_and_merge.h"

const int num_threads = std::thread::hardware_concurrency();

/*------------------------------------------------------------------------------------
 * Function: parallel_insertion_sort
 * Description:
 *
 * Input: Reference to the vector to be sorted (vector<int>&)
 * Output: None (void)
 * Process: The vector to be sorted is passed into separate_vector to be broken into
 *          smaller sub vectors. For the number of threads on the running machine,
 *          a new thread is created and used to run insertion sort on each sub vector.
 *          Threads are then joined and merged using merge_sorted.
 ------------------------------------------------------------------------------------*/
void parallel_insertion_sort(std::vector<int>& items){
    if(items.size() == 0 || items.size() == 1) return;
    std::vector<std::vector<int>> to_sort = separate_vector(items);
    std::vector<std::thread> threads;
    for(int i = 0; i <= num_threads; i++) threads.push_back(std::thread(insertion_sort, ref(to_sort[i])));

    for(int i = 0; i <= num_threads; i++) threads[i].join();

    items = merge_sorted(to_sort);
}

/*------------------------------------------------------------------------------------
 * Function: parallel_merge_sort
 * Description:
 *
 * Input: Reference to the vector to be sorted (vector<int>&)
 * Output: None (void)
 * Process:
 ------------------------------------------------------------------------------------*/
void parallel_merge_sort(std::vector<int>& items) {
    if (items.size() == 0 || items.size() == 1) return;
    std::vector<std::vector<int>> to_sort = separate_vector(items);
    std::vector<std::thread> threads;
    for (int i = 0; i <= num_threads; i++) threads.push_back(std::thread(merge_sort_wrap, ref(to_sort[i])));

    for (int i = 0; i <= num_threads; i++) threads[i].join();

    items = merge_sorted(to_sort);
}

/*------------------------------------------------------------------------------------
 * Function: parallel_quick_sort
 * Description:
 *
 * Input: Reference to the vector to be sorted (vector<int>&)
 * Output: None (void)
 * Process:
 ------------------------------------------------------------------------------------*/
void parallel_quick_sort(std::vector<int>& items) {
    if (items.size() == 0 || items.size() == 1) return;
    std::vector<std::vector<int>> to_sort = separate_vector(items);
    std::vector<std::thread> threads;
    for (int i = 0; i <= num_threads; i++) threads.push_back(std::thread(quick_sort, ref(to_sort[i])));

    for (int i = 0; i <= num_threads; i++) threads[i].join();

    items = merge_sorted(to_sort);
}