#include <iostream>
using namespace std;

void swap(int arr[] , int pos1, int pos2){
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int start, int end){

    int pivotingIndex = start;
    int currentPivotValue = arr[end];

    for (int i = start; i < end; i++)
    {
        if (arr[i] < currentPivotValue)
        {
            swap(arr, i, pivotingIndex);
            pivotingIndex++;
        }
    }

    swap(arr, pivotingIndex, end);
    return pivotingIndex;
}


void quickSort(int arr[], int start, int end){

    if ( start >= end )
        return;

    int index = partition(arr, start, end);

    //left partition
    quickSort(arr, start, index - 1);

    //right partition
    quickSort(arr, index + 1, end);

}

int main()
{
    int numbers[] = {7, 6, 5, 4, 3, 1, 2};
    int n = 7;

    cout<<"The current array is:";
    for( int i = 0 ; i < n; i++){
        cout<< numbers[i] << " ";
    }
    cout << endl;

    quickSort(numbers, 0 , n-1);

    cout<<"The sorted array is: ";
    for( int i = 0 ; i < n; i++){
        cout<< numbers[i]<< " ";
    }

}
