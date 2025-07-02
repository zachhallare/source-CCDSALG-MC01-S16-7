#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/





// Made By: 
void insertionSort(Record *arr, int n)
{
    for (int i = 1; i < n; i++) {
        Record key = arr[i];   
        int j = i - 1;

        while (j >= 0 && arr[j].idNumber > key.idNumber) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;   
    }
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
        int mid = (p + r) / 2;      // Find the middle index.
        mergeSort(arr, p, mid);       // Sort the left half recursively.
        mergeSort(arr, mid + 1, r);     // Sort the right half recursively.

        // Get the lengths of the two halves.
        int firstHalfLen = mid - p + 1;
        int secondHalfLen = r - mid;

        // Temporary array to hold their values (using a dynamic array for large values).
        Record *leftArr = (Record *)malloc(sizeof(Record) * firstHalfLen);
        Record *rightArr = (Record *)malloc(sizeof(Record) * secondHalfLen);

        // Check for allocation failure.
        if (leftArr == NULL || rightArr == NULL) {
            printf("Memory allocation failed in mergeSort.\n");
            exit(1);
        }

        // Copies the data to temp arrays.
        for (int i = 0; i < firstHalfLen; i++) {
            leftArr[i] = arr[p + i];
        }
        for (int j = 0; j < secondHalfLen; j++) {
            rightArr[j] = arr[mid + 1 + j];
        }

        // Merge the sorted backs into the original array.
        int i = 0;      // Left array index.
        int j = 0;      // Right array index.
        int k = p;      // Merged array index.
        while (i < firstHalfLen && j < secondHalfLen) {
            if (leftArr[i].idNumber <= rightArr[j].idNumber) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }

        // Check any remaining elements.
        while (i < firstHalfLen) {
            arr[k++] = leftArr[i++];
        }
        while (j < secondHalfLen) {
            arr[k++] = rightArr[j++];
        }

        // Free the temp arrays.
        free(leftArr);
        free(rightArr);
    }
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/


// Made By:
void bubbleSort(Record *arr, int n)
{
    int i, j;           // Loop counters
    Record temp;        // Used to temporarily hold a Record during swapping

    // Go through the list multiple times
    for (i = 0; i < n - 1; i++) {
        // Compare each pair of Records next to each other
        for (j = 0; j < n - i - 1; j++) {
            // If the current ID is bigger than the next one, swap them
            if (arr[j].idNumber > arr[j + 1].idNumber) {
                temp = arr[j];              
                arr[j] = arr[j + 1];        
                arr[j + 1] = temp;          
            }
        }
    }
}


#endif