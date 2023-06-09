#include <iostream>
#include <vector>
#include "insertion_sort.h"


/*------------------------------------------------------------------------------------
 * Function: insertion_sort
 * Description:
 *
 * Input: Reference to the vector to be sorted (std::vector<int>&)
 * Output: None (void)
 * Process: For the value at each index in the vector, the value before it is
 *          compared to the current value. If this value is less than the current
 *          value, the values are swapped. The index being compared is decreased
 *          and is compared to current index's value again. Process is repeated until
 *          comparing index reaches beginning of the list or until current value
 *          is less than comparing value. Current index then increases by 1.
 ------------------------------------------------------------------------------------*/

void insertion_sort(std::vector<int>& items){
    for(auto curr_idx = 1; curr_idx < items.size(); curr_idx++){
        auto compare_idx = curr_idx - 1;
        const auto curr_val = items[curr_idx];
        while(compare_idx >= 0 && items[compare_idx] > curr_val){
            items[compare_idx + 1] = items[compare_idx];
            compare_idx --;
        }
        items[compare_idx + 1] = curr_val;
    }
}