#include <stdio.h>

//binary search
int binary_search(int size,int *arr,int value){
    int low=0;
    int high=size-1;

    while(low<=high){
        int mid=(high-low)+1/2;
        if (arr[mid]==value){
            return mid;
        }
        else if(arr[mid]<value){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int size,value ,bin_value;
    printf("Enter the Size of array : ");
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        printf("enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search : ");
    scanf("%d",&value);
    
    //binary search calling

    bin_value=binary_search(size,arr,value);
    if (bin_value!=-1)
        printf("Element present in %d th position",bin_value+1);
    else
        printf("Element not found");
}