#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LINE_LENGTH 1024
#define MAX_ROWS 10000


int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *column[MAX_ROWS];
    int row_count = 0;
    file = fopen("C:\\Users\\nagul\\Desktop\\Data structure\\car50000.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    while (fgets(line, sizeof(line), file) != NULL && row_count < MAX_ROWS) {
        line[strcspn(line, "\n")] = '\0';
        char *token = strtok(line, ",");
        if (token != NULL) {
            column[row_count] = strdup(token);
            row_count++;
        }
    }
    int n = sizeof(column)/sizeof(column[0]);
    char *endptr;
    int record[MAX_ROWS];
    for (int i = 0; i < row_count; i++) {
        int num = strtol(column[i], &endptr, 10);
        record[i] = num ;
    }

    clock_t start_time = clock();
    int i,j, key;
    for (int i = 1; i < n; i++) {
        key = record[i];
        j = i - 1;
        while (j >= 0 && record[j] > key) {
            record[j + 1] = record[j];
            j = j - 1;
        }
        record[j + 1] = key;
    }
    clock_t end_time = clock();
    
    for (i = 0; i < row_count; i++) {
        printf("Element %d : %d \n", i+1, record[i]);
        free(column[i]);
    }
    printf("Insertion sort for %d sets \n",i);
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    fclose(file);
    return 0;
}
