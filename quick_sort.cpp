#include <vector>
#include <iostream>
#include <iomanip>

/*------------------------------------------------------------------------------------
 * Function: list_partition
 *
 * Description:
 *
 * Input: Reference to the vector to be sorted(int), start position(int), end position(int)
 * 
 * Output: return pivotingIndex (int)
 * 
 * Process: The 'pivoting_index' is initialized to the start position index at every 
 *          recursive call from the quick_sort function. Then, the 'current_pivot_value'
 *          is initialized to the end parameter which determines the elements that will 
 *          be swapped in 'num_list.' The for loop will be iterating at the starting 
 *          position to the end position at every recursive call until the list is sorted
 *          in ascending order. When the condition, if the current element in num_list is 
 *          less thanthe 'current_pivot_value,' the two elements swap position, and the 
 *          pivot index increments to the next element. At the end of the for loop, the 
 *          value at the 'pivoting_index' will be swapped with the end position value in 
 *          the list showing the sub-array for either the right or left list partition is 
 *          completed and in ascending order based on the passed parameters. When sorting 
 *          the sub-arrays, the returning value 'pivoting_index' will continue the sorting 
 *          process to the next or previous element in 'num_list.'  
 ------------------------------------------------------------------------------------*/
int list_partition(std::vector<int>& num_list, int start_position, int end_position) 
{
    //index moving during every for loop iteration 
    int pivoting_index = start_position;

    //Current pivot value at every quick_sort_algorithm recursive call
    int current_pivot_value = num_list[end_position];

    //Iterating through num_list from passed start to end position
    for (int i = start_position; i < end_position; i++) 
    {
        //If the current element is less than the current pivot
        if (num_list[i] < current_pivot_value) 
        {   
            //swap values
            std::swap(num_list[i], num_list[pivoting_index]);

            //increment to the next index after swapping
            pivoting_index++;
        }
    }
    
    //Once iterative swapping is completed, swap the pivot and the
    //incrementing pivot index to finsh the sub-array sort
    std::swap(num_list[pivoting_index], num_list[end_position]);
    
    //Returning the pivoting index begin the next portion of sorting
    return pivoting_index;
}

/*------------------------------------------------------------------------------------
 * Function: quick_sort_algorithm
 *
 * Description:
 *
 * Input: Reference to vector of numbers(int), starting position(int), end position(int)
 * 
 * Output: None (void)
 * 
 * Process: The 'quick_sort_algorithm' is a divide-and-conquer algorithm that takes 
 *          'num_list' and divides the elements into sub-vectors. The purpose of sorting 
 *          the sub-vectors is to sort the various size of num_list quickly and efficiently. 
 *          The method takes in 3 parameters which are the references to the elements in 
 *          'num_list,' the value for the 'start_position,' and the 'end_position' that 
 *          is the size of the 'num_list.' An if statement is placed to check whether the 
 *          start and end positions are either the same value or have crossed. This 
 *          signifies within the recursive sorting algorithm that num_list is sorted 
 *          in numerically ascending order. However, if the condition is not met, the 
 *          index variable will hold the index value of the next sub-vectors to be sorted. 
 ------------------------------------------------------------------------------------*/

void quick_sort_algorithm(std::vector<int>& num_list, int start_position, int end_position) 
{
    //Check if num_list is sorted
    //if the two positions cross or equal, stop sorting
    if (start_position >= end_position)
        return;

    int index = list_partition(num_list, start_position, end_position);

    //Left partition of list
    quick_sort_algorithm(num_list, start_position, index - 1);

    //Right partition of list
    quick_sort_algorithm(num_list, index + 1, end_position);
}

void quick_sort(std::vector<int>& items){
    quick_sort_algorithm(items, 0, items.size() - 1);
}