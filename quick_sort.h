#ifndef QUICK_SORT_ALGORITHM_H
#define QUICK_SORT_ALGORITHM_H

#include <vector>
#include <iostream>
#include <iomanip>

int list_partition(std::vector<int>& num_list, int start_position, int end_position);

void quick_sort_algorithm(std::vector<int>& num_list, int start_position, int end_position);

void quick_sort(std::vector<int>& items);

#endif //DSA_FINAL_PROJECT_QUICK_SORT_H