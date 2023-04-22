#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include "parallel_insertion_sort.h"
#include "insertion_sort.h"

int num_threads = std::thread::hardware_concurrency();

/*------------------------------------------------------------------------------------
 * Function: separate_vector
 * Description:
 *
 * Input: Reference to the vector to be sorted (vector<int>&)
 * Output: Vector containing separated pieces of the input vector (2-D vector)
 * Process: The size of each sub vector is determined by the number of threads on the
 *          working machine. The size of the original vector is divided by number of
 *          threads and rounded up or down, resulting in size of sub vectors. The outer
 *          loop ensures the vector has one less inner vector than the number of threads.
 *          The inner loop ensures the size of each sub vector matches the determined
 *          size. The inner loop pushes elements from items to sub vectors of the
 *          appropriate size.
 ------------------------------------------------------------------------------------*/
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
    // Pushes any remaining numbers to the separated vector
    if(!items.empty()) separated_vec.push_back(items);
    return separated_vec;
}

/*------------------------------------------------------------------------------------
 * Function: merge_sorted
 * Description:
 *
 * Input: Reference to the vector which has been sorted (vector<int>&)
 * Output: Merged vector of sorted elements (vector<int>)
 * Process: Function loops through each sorted vector in the 2-D vector and compares
 *          the last element in each one (largest number in each). Once the largest
 *          out of all of them is found, it is pushed to a new 1-D vector and deleted
 *          from the original 2-D vector. The new vector is reversed, resulting in a
 *          sorted vector.
 ------------------------------------------------------------------------------------*/
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
    std::reverse(final_vec.begin(), final_vec.end());
    return final_vec;
}

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