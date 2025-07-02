#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100000
#define DATASET_COUNT 7


int main()
{
    char datasets[DATASET_COUNT][100] = {
        "data/almostsorted.txt",
        "data/random100.txt",
        "data/random25000.txt",
        "data/random50000.txt",
        "data/random75000.txt",
        "data/random100000.txt",
        "data/totallyreversed.txt"
    };

    Record records[MAX_RECORDS];
    int n;

    for (int d = 0; d < DATASET_COUNT; d++) {
        printf("===== Dataset: %s =====\n", datasets[d]);

        FILE *fp = fopen(datasets[d], "r");
        if (fp == NULL) {
            printf("Failed to open file: %s\n", datasets[d]);
            continue;
        }

        fscanf(fp, "%d\n", &n);  // number of records

        for (int i = 0; i < n; i++) {
            fscanf(fp, "%d", &records[i].idNumber);
            fgetc(fp); // consume space
            fgets(records[i].name, 500, fp);
            records[i].name[strcspn(records[i].name, "\n")] = 0; // remove newline
        }

        fclose(fp);

        // Print first 10 records
        for (int i = 0; i < 10 && i < n; i++) {
            printf("%d %s\n", records[i].idNumber, records[i].name);
        }

        printf("\n");
    }

    return 0;
}