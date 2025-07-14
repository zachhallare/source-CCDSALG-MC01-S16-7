#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/


// Made By: Joshua Carlos Samonte
void insertionSort(Record *arr, int n, long long *stepCounter)
{
    for (int i = 1; i < n; i++) {
        Record key = arr[i];   
        int j = i - 1;

        while (j >= 0 && arr[j].idNumber > key.idNumber) {
            (*stepCounter)++;       // comparison.
            arr[j + 1] = arr[j];
            (*stepCounter)++;       // move.
            j--;
        }

        if (j >= 0) {
            (*stepCounter)++;       // final comparison when while condition fails.
        }

        arr[j + 1] = key;   
        (*stepCounter)++;       // insertion.
    }
}


// Made By: Santino Jose Suarez
void selectionSort(Record *arr, int n, long long *stepCounter)
{
    int i, j, min; 
    Record temp; 

    for (i = 0; i < n; i++)
    {
        min = i; // Sets  min to value at index 0.

        for (j = i + 1; j < n; j++)
        {
            (*stepCounter)++;   // comparison.
            if(arr[j].idNumber < arr[min].idNumber)
            {
                min = j; // Updates min to value at index j (new minimum).
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        (*stepCounter) += 3;    // swap.
    }
}


// Made By: Zach Benedict Hallare
void mergeSort(Record *arr, int p, int r, long long *stepCounter)
{
    // Checks if there's more than one element in the array.
    if (p < r) {
        int mid = (p + r) / 2;      // Find the middle index.
        mergeSort(arr, p, mid, stepCounter);       // Sort the left half recursively.
        mergeSort(arr, mid + 1, r, stepCounter);     // Sort the right half recursively.

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
            (*stepCounter)++;   // copy.
        }
        for (int j = 0; j < secondHalfLen; j++) {
            rightArr[j] = arr[mid + 1 + j];
            (*stepCounter)++;   // copy.
        }

        // Merge the sorted backs into the original array.
        int i = 0;      // Left array index.
        int j = 0;      // Right array index.
        int k = p;      // Merged array index.
        while (i < firstHalfLen && j < secondHalfLen) {
            (*stepCounter)++;   // comparison.
            if (leftArr[i].idNumber <= rightArr[j].idNumber) {
                arr[k++] = leftArr[i++];
                (*stepCounter)++;       // merge step.
            } else {
                arr[k++] = rightArr[j++];
                (*stepCounter)++;       // merge step.
            }
        }

        // Check any remaining elements.
        while (i < firstHalfLen) {
            arr[k++] = leftArr[i++];
            (*stepCounter)++;       // merge remainder.
        }
        while (j < secondHalfLen) {
            arr[k++] = rightArr[j++];
            (*stepCounter)++;       // merge remainder.
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


//Made By: Rhaizza Mariel Legaspi
void quickSort(Record *arr, int n, long long *stepCounter)
{
	// Temporary array to simulate a recursion (stack)
    int auxArray[n];
    int top = -1;
    int high, low, pivot, i, j, pivotIndex;

	// this will push initial range (start and the end of the array)
    auxArray[++top] = 0;
    auxArray[++top] = n - 1;

    while (top >= 0) {
        // This will pop the current range to sort
		high = auxArray[top--];
        low = auxArray[top--];

        // this will choose the last element as the pivot
        pivot = arr[high].idNumber;
        i = low - 1;
		
		//this will rearrange elements around the pivot
        for (j = low; j < high; j++) {
            (*stepCounter)++; // compare
            if (arr[j].idNumber < pivot) {
                i++;
                Record temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                (*stepCounter) += 3; // swap
            }
        }

        // This will move pivot to its correct position
        Record temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        (*stepCounter) += 3; // swap
        pivotIndex = i + 1;

        // If there are elements on the left, push that range
        if (pivotIndex - 1 > low) {
            auxArray[++top] = low;
            auxArray[++top] = pivotIndex - 1;
        }

        // If there are elements on the right, push that range
        if (pivotIndex + 1 < high) {
            auxArray[++top] = pivotIndex + 1;
            auxArray[++top] = high;
        }
    }
	
	
}


#endif