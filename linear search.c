#include <stdio.h>

int main(){
    int size,value;
    printf("Enter the Size of array : ");
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        printf("enter the element %d : ",i);
        scanf("%d",&arr[i]);
    }
    printf("ENter the element to search : ");
    scanf("%d",&value);
    //linear search
    for (int j =0 ;j<size;j++){
        if (arr[j]==value){
            printf("Element found at %d th position",j+1);
            break;
        }
    }
}