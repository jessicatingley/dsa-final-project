#ifndef DSA_FINAL_PROJECT_MERGE_SORT_H
#define DSA_FINAL_PROJECT_MERGE_SORT_H

#include <iostream>
#include <vector>

void merge(std::vector<int>& vec, int low, int mid, int high);

void merge_sort(std::vector<int>& vec,  int low, int high);

void merge_sort_wrap(std::vector<int>& items);

#endif //DSA_FINAL_PROJECT_MERGE_SORT_H
