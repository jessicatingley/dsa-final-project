#include <iostream>
#include <vector>
#include <cstring>
#include "merge_sort.h"


/*------------------------------------------------------------------------------------
 * Function: merge
 * Description:
 *
 * Input: Reference to the vector to be sorted (int), low value, mid value, high value
 * Output: None (void)
 * Process:  Creates a temporary vector and has variables i and j to keep track of the
 *           first element in the left and right partitions. For each half, the elements
 *           at index i and j is compared and the lower of the 2 elements is added to
 *           the temp vector. This process continues as long as i does not reach the
 *           midpoint and j does not reach the high point. After this is over, the
 *           leftover elements are copied to the temp vector from the left side, and
 *           then the right. Finally, the elements in the temp vector are copied back
 *           to the original vector.
 ------------------------------------------------------------------------------------*/
void merge(std::vector<int>& vec, int low, int mid, int high){

    //create temp vector 
    std::vector<int> temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        }
        else {
            temp[k++] = vec[j++];
        }
    }
    
    //copy left over elements from left and right side
    while (i <= mid) {
        temp[k++] = vec[i++];
    }
    
    while (j <= high) {
        temp[k++] = vec[j++];
    }

    //copy data back into vec
    std::memcpy(&vec[low], &temp[0], temp.size() * sizeof(int));
}

/*------------------------------------------------------------------------------------
 * Function: merge_sort
 * Description:
 *
 * Input: Reference to the vector to be sorted (int), low value, high value
 * Output: None (void)
 * Process: Recursively break down vector into 2 halves by dividing vector in half and
 *          calling merge_sort on each half. End when the high value is less than or
 *          equal to the low value. Then merge the 2 halves together using the merge
 *          function.
 ------------------------------------------------------------------------------------*/
void merge_sort(std::vector<int>& vec, int low, int high){
    if(high <= low){
        return;
    }

    int mid = low + (high - low) / 2;

    merge_sort(vec, low, mid);
    merge_sort(vec, mid + 1, high);
    merge(vec, low, mid, high);

}

void merge_sort_wrap(std::vector<int>& items){
    merge_sort(items, 0, items.size() - 1);
}