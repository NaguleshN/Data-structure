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
    clock_t t;
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
    int i,val,j,option;
    printf("Enter the option : ");
    scanf("%d",&option);
    int low=0,high=n-1,mid;
    printf("Enter the Element : ");
    scanf("%d",&val);
    switch(option){
        case 1:
    t = clock();
        for (i=0;i<n;i++){
        if (record[i]==val){
            printf("Found");
            break;
        }
        printf("not found");
    t = clock()-t;
        break;
        case 2:
            
        t= clock();
            while(low<=high){
                mid=(high+low)/2;
                if (record[mid] == val)
                {
                    printf("found");
                    break;
                }
                else if(record[mid] < val)
                {
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            printf("not found");
        t= clock()-t;
            break;
            }
    
    }


    
    
    
    // for (i = 0; i < row_count; i++) {
    //     printf("Element %d : %d \n", i+1, record[i]);
    //     free(column[i]);
    // }
    // printf("Insertion sort for %d sets \n",i);
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    fclose(file);
    return 0;
}
