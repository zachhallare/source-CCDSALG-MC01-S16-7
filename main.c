#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>     // Added so we can use dynamic arrays.

#define DATASET_COUNT 7
#define REPEAT_COUNT 5

int main()
{
    char datasets[DATASET_COUNT][100] = {
        "data/random100.txt",
        "data/random25000.txt",
        "data/random50000.txt",
        "data/random75000.txt",
        "data/random100000.txt",
        "data/almostsorted.txt",
        "data/totallyreversed.txt"
    };

    for (int i = 0; i < DATASET_COUNT; i++) {
        char filepath[500];
        strcpy(filepath, datasets[i]);
        printf("\n==============================\n");
        printf("Dataset: %s\n", filepath);
        printf("==============================\n");

        // Get the number of records.
        int numberOfRecords = 0;
        FILE *fp = fopen(filepath, "r");
        if (fp == NULL) {
            printf("Failed to open file.\n");
            continue;
        }
        fscanf(fp, "%d", &numberOfRecords);
        fclose(fp); 

        // Read the records into originalRecords
        Record *originalRecords = malloc(sizeof(Record) * numberOfRecords);
        if (originalRecords == NULL) {
            printf("Memory allocation failed.\n");
            continue;
        }
        readFile(originalRecords, filepath);

        // Create reusable temp array for each algorithm.
        Record *tempArr = malloc(sizeof(Record) * numberOfRecords);

        // For each algorithm, repeat least 5x and average.
        long totalTime;
        long long totalSteps;


        // --------- Insertion Sort ---------
        totalTime = 0;
        totalSteps = 0;
        for (int r = 0; r < REPEAT_COUNT; r++) {
            memcpy(tempArr, originalRecords, sizeof(Record) * numberOfRecords);
            long long steps = 0;
            long start = currentTimeMillis();
            insertionSort(tempArr, numberOfRecords, &steps);
            long end = currentTimeMillis();
            totalTime += (end - start);
            totalSteps += steps;
        }
        printf("Insertion Sort - Avg Time: %ld ms | Avg Steps: %lld\n", totalTime / REPEAT_COUNT, totalSteps / REPEAT_COUNT);


        // --------- Selection Sort ---------
        totalTime = 0;
        totalSteps = 0;
        for (int r = 0; r < REPEAT_COUNT; r++) {
            memcpy(tempArr, originalRecords, sizeof(Record) * numberOfRecords);
            long long steps = 0;
            long start = currentTimeMillis();
            selectionSort(tempArr, numberOfRecords, &steps);
            long end = currentTimeMillis();
            totalTime += (end - start);
            totalSteps += steps;
        }
        printf("Selection Sort - Avg Time: %ld ms | Avg Steps: %lld\n", totalTime / REPEAT_COUNT, totalSteps / REPEAT_COUNT);


        // --------- Merge Sort ---------
        totalTime = 0;
        totalSteps = 0;
        for (int r = 0; r < REPEAT_COUNT; r++) {
            memcpy(tempArr, originalRecords, sizeof(Record) * numberOfRecords);
            long long steps = 0;
            long start = currentTimeMillis();
            mergeSort(tempArr, 0, numberOfRecords - 1, &steps);
            long end = currentTimeMillis();
            totalTime += (end - start);
            totalSteps += steps;
        }
        printf("Merge Sort - Avg Time: %ld ms | Avg Steps: %lld\n", totalTime / REPEAT_COUNT, totalSteps / REPEAT_COUNT);

        
        // --------- Bubble Sort ---------
        totalTime = 0;
        totalSteps = 0;
        for (int r = 0; r < REPEAT_COUNT; r++) {
            memcpy(tempArr, originalRecords, sizeof(Record) * numberOfRecords);
            long long steps = 0;
            long start = currentTimeMillis();
            bubbleSort(tempArr, numberOfRecords, &steps);
            long end = currentTimeMillis();
            totalTime += (end - start);
            totalSteps += steps;
        }
        printf("Bubble Sort - Avg Time: %ld ms | Avg Steps: %lld\n", totalTime / REPEAT_COUNT, totalSteps / REPEAT_COUNT);


        // Cleanup the dynamic arrays.
        free(originalRecords);
        free(tempArr);
    }

    return 0;
}