#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // Added so we can use dynamic arrays.

int main()
{
    char datasets[7][100] = {
        "data/random100.txt",
        "data/random25000.txt",
        "data/random50000.txt",
        "data/random75000.txt",
        "data/random100000.txt",
        "data/almostsorted.txt",
        "data/totallyreversed.txt"
    };

    for (int i = 0; i < 7; i++) {
        char filepath[500];
        strcpy(filepath, datasets[i]);
        printf("\n==============================\n");
        printf("Dataset: %s\n", filepath);
        printf("==============================\n");

        int numberOfRecords = 0;

        // Open the file and read the first line (number of records)
        FILE *fp = fopen(filepath, "r");
        if (fp == NULL) {
            printf("Failed to open file.\n");
            return 1;
        }
        fscanf(fp, "%d", &numberOfRecords);
        fclose(fp);  // Close after reading the first line

        // Now we know how many records to allocate and print
        Record *originalRecords = malloc(sizeof(Record) * numberOfRecords);
        if (originalRecords == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // Read all records using the given readFile function
        readFile(originalRecords, filepath);

        // Create copies for each part
        Record *insertionArr = malloc(sizeof(Record) * numberOfRecords);
        Record *selectionArr = malloc(sizeof(Record) * numberOfRecords);
        Record *mergeArr = malloc(sizeof(Record) * numberOfRecords);
        Record *bubbleArr = malloc(sizeof(Record) * numberOfRecords);

        for (int j = 0; j < numberOfRecords; j++) {
            insertionArr[j] = originalRecords[j];
            selectionArr[j] = originalRecords[j];
            mergeArr[j] = originalRecords[j];
            bubbleArr[j] = originalRecords[j];
        }

        long startTime, endTime, executionTime;

        // Insertion Sort.
        startTime = currentTimeMillis(); 
        insertionSort(insertionArr, numberOfRecords);
        endTime = currentTimeMillis();  
        executionTime = endTime - startTime;
        printf("Insertion Sort - Time: %ld ms\n", executionTime);

        // Selection Sort.
        startTime = currentTimeMillis(); 
        selectionSort(selectionArr, numberOfRecords);
        endTime = currentTimeMillis();  
        executionTime = endTime - startTime;
        printf("Selection Sort - Time: %ld ms\n", executionTime);

        // Merge Sort.
        startTime = currentTimeMillis(); 
        mergeSort(mergeArr, 0, numberOfRecords - 1);
        endTime = currentTimeMillis();  
        executionTime = endTime - startTime;
        printf("Merge Sort - Time: %ld ms\n", executionTime);

        // Bubble Sort.
        startTime = currentTimeMillis(); 
        bubbleSort(bubbleArr, numberOfRecords);
        endTime = currentTimeMillis();  
        executionTime = endTime - startTime;
        printf("Bubble Sort - Time: %ld ms\n", executionTime);

        // Deallacated memory for safety.
        free(originalRecords);
        free(insertionArr);
        free(selectionArr);
        free(mergeArr);
        free(bubbleArr);
    }

    return 0;
}