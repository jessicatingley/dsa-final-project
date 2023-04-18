#ifndef DSA_FINAL_PROJECT_QUICK_SORT_H
#define DSA_FINAL_PROJECT_QUICK_SORT_H

#include <iostream>
#include <vector>

int swap_function(std::vector<int>& vec, int startPos, int endPos);

void quick_sort(std::vector<int>& vec,  int startPos, int endPos);

void quick_sort_wrap(std::vector<int>& items);

#endif //DSA_FINAL_PROJECT_QUICK_SORT_H