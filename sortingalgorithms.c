#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/





// Made By: 
void insertionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.






}

// Made By: 
void selectionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.






}

// Made By: Zach Benedict Hallare
void mergeSort(Record *arr, int p, int r)
{
    // Checks if there's more than one element in the array.
    if (p < r) {
        int nMid = (p + r) / 2;      // Find the middle index.
        mergeSort(arr, p, nMid);       // Sort the left half recursively.
        mergeSort(arr, nMid + 1, r);     // Sort the right half recursively.

        // Get the lengths of the two halves.
        int nFirstHalfLen = nMid - p + 1;
        int nSecondHalfLen = r - nMid;

        // Temporary array to hold their values.
        Record leftArr[nFirstHalfLen];
        Record rightArr[nSecondHalfLen];

        // Copies the data to each array.
        for (int i = 0; i < nFirstHalfLen; i++) {
            leftArr[i] = arr[p + i];
        }
        for (int j = 0; j < nSecondHalfLen; j++) {
            rightArr[j] = arr[nMid + 1 + j];
        }

        // Merge the sorted backs into the original array.
        int i = 0;      // Left array index.
        int j = 0;      // Right array index.
        int k = p;      // Merged array index.

        while (i < nFirstHalfLen && j < nSecondHalfLen) {
            if (leftArr[i].idNumber <= rightArr[j].idNumber) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }

        // Check if there are remaining elements, copy them.
        while (i < nFirstHalfLen) {
            arr[k++] = leftArr[i++];
        }
        while (j < nSecondHalfLen) {
            arr[k++] = rightArr[j++];
        }
    }
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/


// Made By:
void BinarySort(Record *arr, int n)
{


}










#endif