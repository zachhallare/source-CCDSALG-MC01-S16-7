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

    int choice = -1;

    while (choice != 0) {
        printf("\n======[ PICK A DATASET ]======\n");
        for (int i = 0; i < DATASET_COUNT; i++) {
            printf("%d. %s\n", i + 1, datasets[i]);
        }
        printf("0. Exit.");
        printf("\n==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= DATASET_COUNT) {
            int datasetIndex = choice - 1;
            char filepath[500];
            strcpy(filepath, datasets[datasetIndex]);
            printf("\n\n==============================\n");
            printf("Dataset: %s\n", filepath);
            printf("==============================\n");

            // Get the number of records.
            int numberOfRecords = 0;
            FILE *fp = fopen(filepath, "r");
            if (fp == NULL) {
                printf("Failed to open file.\n");
            } else {
                fscanf(fp, "%d", &numberOfRecords);
                fclose(fp); 

                // Read the records into originalRecords
                Record *originalRecords = malloc(sizeof(Record) * numberOfRecords);
                Record *tempArr = malloc(sizeof(Record) * numberOfRecords);
                if (originalRecords == NULL || tempArr == NULL) {
                    printf("Memory allocation failed.\n");
                } else {
                    readFile(originalRecords, filepath);

                    // For each algorithm, repeat least 5x and average (in the specs).
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
                    printf("%-15s - Avg Time: %3ld ms | Avg Steps: %6lld\n", 
                        "Insertion Sort", totalTime / REPEAT_COUNT, totalSteps / REPEAT_COUNT);

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
                    printf("%-15s - Avg Time: %3ld ms | Avg Steps: %6lld\n", 
                        "Selection Sort", totalTime / REPEAT_COUNT, totalSteps / REPEAT_COUNT);

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
                    printf("%-15s - Avg Time: %3ld ms | Avg Steps: %6lld\n", 
                        "Merge Sort", totalTime / REPEAT_COUNT, totalSteps / REPEAT_COUNT);
                    
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
                    
                    printf("%-15s - Avg Time: %3ld ms | Avg Steps: %6lld\n", 
                        "Bubble Sort", totalTime / REPEAT_COUNT, totalSteps / REPEAT_COUNT);
                    
                    // Cleanup the dynamic arrays.
                    free(originalRecords);
                    free(tempArr);

                    printf("\n\n");
                }
            }
        } else if (choice != 0) {
            printf("Invalid choice. Please enter a number from 0 to 7.\n");
        }
    }

    printf("\nProgram has been terminated.\n");
    return 0;
}