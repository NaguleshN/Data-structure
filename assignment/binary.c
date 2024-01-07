#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LINE_LENGTH 1024
#define MAX_ROWS 1120000

int binarySearch(int arr[],int size,int val){
    for (int i=0;i<size;i++){
        if (arr[i]==val){
            printf("Found");
            return i+1;
        }
}
        printf("not found");
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *column[MAX_ROWS];
    clock_t t;
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
    fclose(file);
    int n = sizeof(column)/sizeof(column[0]);
    char *endptr;
    int record[MAX_ROWS];
    for (int i = 0; i < row_count; i++) {
        int num = strtol(column[i], &endptr, 10);
        record[i] = num ;
    }
    int val;
    printf("Enter the Element : ");
    t = clock(); 
    scanf("%d",&val);
    if(binarySearch(record,n,val)==-1){
        printf("Element not found\n");
    }
    t = clock()-t;
    printf("search for %d datas \n",MAX_ROWS);
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}

