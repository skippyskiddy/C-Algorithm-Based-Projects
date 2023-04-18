#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array.
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]


int findMinimum(int *array, int start, int stop)
{
    if (array == NULL || start < 0 || stop < 0 || start > stop) // error checking for various conditions 
    // exit if null, if start/stop is a negative number, and if start is larger than stop. 
    {
        return -1; 
    }
    int i; //declare to compile with gcc
    int current_minimum = start; // the start index is the initialized minimum.
    for (i = start + 1; i <= stop; i++) // compare the current minimum with value on right side of the array. 
    {
        if (array[i] < array[current_minimum]) // if any elemnt is smaller than the current minimum.
        {
            current_minimum = i; //set the index of the smaller element to the current minimum. 
        }
    }

    return current_minimum; //return the smallest element between (including) the start and stop indexes. 
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    int i, j, min_index; 
  
    // Outer loop to iterate through the sorted array 
    for (i = 0; i < size; i++)
    {
        // Inner loop that points to a rightward value 
        // and iteraes through the unsorted array of numbers 
        // to find minimums to swap to the i index. 
        min_index = i;

        for (j = i; j < size; j++)
        { 
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        if(min_index != i) {
            swap(&array[min_index], &array[i]);
        }

        if (print == 1) {
            printIntArray(array, size);
        }
    }
}



/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.


void insertionSortIntegers(int *array, unsigned int size, int print)
{
    int i, j, temp;
    for (i = 1; i < size; i++) { //loop to traverse the array and compare it with the digit on the right. 
        temp = array[i]; //the analyzed index of the array is stored in temp 
        j = i - 1; //initialize the sorted array (-1 since it starts at the second index)

        while (j >= 0 && array[j] > temp) { //compare each new temp element to everything in the sorted array to find correct position
            swap(&array[j], &array[j+1]); //move elements up as the sorted array is traversed 
            j = j - 1; //move backwards 
        }
        array[j + 1] = temp; //once correct position is found insert temp into the correct j index 

        if (print == 1) {
            printIntArray(array, size);
        }
    }   
}


/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.


void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    int i, j;

    // Loop over the array 'size-1' times
    for (i = 0; i < size - 1; i++) { //bubble sort continues to do this even if the list is sorted 

        // loop to go over array and swap items if the rightmost item is bigger 
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) { // if the leftmost item is bigger 
                // Swap using sort helper function 
                swap(&array[j], &array[j+1]);
            }
        }

        if (print == 1) {
            printIntArray(array, size);
        }
    }
}



// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
//function compares the elements in the two arrays and merges them in the temp array
{
    if (arr == NULL || temp == NULL) { //check if null, exit if it is 
        exit(1);
    }

    int i, j, k; //initialize the indexes to iterate over the subarrays
    i = l;      // Starting indx for left subarray
    j = m + 1;  // Starting index for right subarray
    k = l;      // Starting index for temp array

    // Merge the two subarrays into temp array
    while (i <= m && j <= r) { // while both subarrays are less than their last index, exits if any of them runs out
        if (arr[i] <= arr[j]) { //compare the element in the left array with the current element in the right array 
            temp[k++] = arr[i++]; //if it is smaller than or equal to, then the current element is copied to the temp array
        } else { //if right subarray element is bigger, copy that to temp 
            temp[k++] = arr[j++];  
        }
    }

    // Copy any remaining elements from the left subarray to temp array
    // if the size of the two subarrays is not equal 
    // and one fo them runs out before the other 
    while (i <= m) {
        temp[k++] = arr[i++];
    }

    // Copy any remaining elements from the right subarray to temp array
    //if sizes are uneven 
    while (j <= r) {
        temp[k++] = arr[j++];
    }

    // Copy merged elements from temp array to original array and return
    for (i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
    if (arr == NULL || temp == NULL) { // Check if null, exit if it is 
        exit(1);
    }

    if (l < r) { // if the first index is less than the last index (check if there is only 1 element in the array)
        int m = (l + r) / 2; // the middle point 

        // Sort first and second halves
        merge_sort(arr, temp, l, m); //recursively call itself to break down and sort the left side 
        merge_sort(arr, temp, m + 1, r); //recursively call itself to break down and sort the right side
        //if both are 1 item then start sorting 

        // Merge the sorted halves
        merge(arr, temp, l, m, r); //merge the two halves 
    }
}


void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
// I assume print is kept for consistent function inputs 
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
    {
        return;
    }

    int *temp = (int *)malloc(sizeof(int) * size); //malloc space for the temp array
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif
