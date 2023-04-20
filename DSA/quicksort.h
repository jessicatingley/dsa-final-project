
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>

int swap_function(std::vector<int>& vec, int startPos, int endPos);

void quick_sort(std::vector<int>& vec,  int startPos, int endPos);

#endif // QUICKSORT_H
