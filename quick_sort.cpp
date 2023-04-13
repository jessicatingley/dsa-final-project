#include "quick_sort.h"

#include <iostream>
#include <vector>


/*------------------------------------------------------------------------------------
 * Function: swap_function
 *
 * Description: The swap_function's scope is to find when a number in the vector that 
 *              is less than and greater than the pivoting index in the vector.
 *
 * Input: Reference to the vector to be sorted (int), start position (int), 
 *          end position (int)
 * 
 * Output: i (int)
 * 
 * Process: In the nested while loops the conditions increment 'i' and decrement 'j' 
 *          when both conditions are met. Once this is true for both conditions, a 
 *          manual swap is preformed for both values and the function will return 'i'. 
 *          This values is the next pivoting index for the continuing swap in the vector 
 *          of numbers. Finally after every swap_function call, the start position and 
 *          end position move after every successful swap.
 ------------------------------------------------------------------------------------*/

int swap_function(std::vector<int> &vec,  int startPos, int endPos){

    //Getting the pivoting index for the search
    int pivot = startPos + (endPos - startPos) / 2;

    //Saving the value in the vec at the pivot index
    int value = vec[pivot];

    //Variable 'i' and 'j' will be holding the starting and ending postions
    int i = startPos;
    int j = endPos;

    //Variable 'tempValue' is initalized for helping swapping the two values in
    //the while loops below 
    int tempValue;

    //While Loop: 'i' is moving left -> right in vec
    //            'j' is moving right -> left in vec
    //
    //Condition: The while loop with stop when j is greater than i. This represents
    //           the end position has moved passed the start position. 
    while ( i <= j)
    {
        //Incrementing 'i' in the while loop until the current element in the vector
        //is greater than the pivoting index
        while (vec[i] < value)
            i++;
        
        //Decrementing 'j' in the while loop until the current element in the vector
        //is less than the value at the pivoting index
        while (vec[j] > value)
            j--;
        
        //Ensuring a swap is possible based on the two previous while loops
        if (i <= j)
        {
            //Preforming a manual swap
            tempValue = vec[i];
            vec[i] = vec[j];
            vec[j] = tempValue;

            //Moving the start position +1
            //Moving the end positiotn -1
            i++;
            j--;
        }
    }

    //After loop is completed return 'i', which is the new start position
    //Thus, making a new pivoting index for each recursive case after every swap
    return i;


}

/*------------------------------------------------------------------------------------
 * Function: quick_sort
 * Description: The function will recusively swap elements until the start position in 
 *              the vector is greater than the ending position in the vector. Once the 
 *              stoping condition is met, the vector of numbers have been sorted in
 *              ascending order.
 *
 * Input: Reference to the vector to be sorted (int), recursive start position (int),
 *        recursive end position (int)
 * 
 * Output: i (int)
 * 
 * Process: If the starting position is less then the ending position in the vector, 
 *          then the function will continue to swap numbers. After every swap, a new 
 *          pivoting index is calculated and the next sorting recursive call is
 *          preformed. However, if the condition value is ending position being less 
 *          than the starting position, the recursive call will stop. This signifies
 *          that the entire vector is sorted in ascending order.
 ------------------------------------------------------------------------------------*/

void quick_sort(std::vector<int> &vec,  int startPos, int endPos){

    if (startPos < endPos)
    {
        //Getting pivoting index
        int pivotingIndex = swap_function(vec, startPos, endPos);

        //Preforming recursive calls for swapping elements
        quick_sort(vec, startPos, pivotingIndex - 1);
        quick_sort(vec, pivotingIndex, endPos);
    }
}