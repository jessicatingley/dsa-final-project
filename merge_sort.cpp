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
 * Process: Creates an auxillary vector and copies data from the vector being sorted to this new one. Starting the process of merging the 2 halves of the vector: the left sub-vector goes from low to mid and the right sub-vector goes from mid+1 to high. i starts at low and j starts at mid+1. The left and right sub-vectors are merged using a loop to iterate from low to high. For each index, there are multiple comparisons being made: 
 *          The low is compared the the mid, and if it's greater, then the element at index j is added to the vector. 
 *          The elements in the right sub-vector are compared to the high and if it's greater, the element at index i is added to the vector.
 *          The elements at j and i are compared and if the element at j is less than the element at i, the element at j is added to the vector.
 *If none of the conditions are met, then the element at index i is added to the vector.
 ------------------------------------------------------------------------------------*/
void merge(std::vector<int>& vec, int low, int mid, int high){
    std::vector<int> aux(vec.size());

    std::memcpy(&aux[low], &vec[low], (high - low + 1) * sizeof(int));

    int i = low;
    int j = mid + 1;

    for(int k = low; k <= high; k++){
        if(i > mid){
            vec[k] = aux[j++];
        }
        else if(j > high){
            vec[k] = aux[i++];
        }
        else if(aux[j] < aux[i]){
            vec[k] = aux[j++];
        }
        else{
            vec[k] = aux[i++];
        }
    }
}

/*------------------------------------------------------------------------------------
 * Function: merge_sort
 * Description:
 *
 * Input: Reference to the vector to be sorted (int), low value, high value
 * Output: None (void)
 * Process: Recursively break down vector into 2 halves by dividing vector in half and calling merge_sort on each half. End when the high value is less than or equal to the low value. Then merge the 2 halves together using the merge function.
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