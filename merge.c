#include <stdio.h>

void merge(int arr[],int low,int mid,int high){

int i=low;
int j=mid+1;
int b[(high-low)+1];
int q=0;


while(i<=mid&&j<=high){
    if(arr[i]<=arr[j]){
        b[q]=arr[i];
        i++;
    }
    else{

        b[q]=arr[j];
        j++;
    }q++;
}



while(i<=mid){

    b[q]=arr[i];
    i++;q++;

}

while(j<=high){

    b[q]=arr[j];
    j++;q++;
}

for (int i=low;i<=high;i++){
    arr[i]=b[i-low];
}
}

/*
void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int b[(high - low) + 1];

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        b[k] = arr[j];
        j++;
        k++;
    }

    for (int x = low; x <= high; x++) {
        arr[x] = b[x - low];
    }
}


*/
void mergesort(int arr[],int low,int high){
    if(low<high){

int mid=(low+high)/2;
mergesort(arr,low,mid);
mergesort(arr,mid+1,high);
merge(arr,low,mid,high);

}
}

void printarray(int arr[],int N)
{
    for(int i=0;i<N;i++){

        printf("%d",arr[i]);
    }
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    //printf("Given array is \n");
    //printarray(arr, arr_size);

    mergesort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printarray(arr, arr_size);
    return 0;
}
