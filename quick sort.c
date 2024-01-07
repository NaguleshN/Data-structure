void swap(int *a,int *b){
int temp=*a;
*a=*b;
*b=temp;

}

int partition(int arr[],int low,int high){

    swap(&arr[(high+low)/2],&arr[high]);
    int pivot=arr[high];
    int start=low;
    int end=high;
    while(start<end){
    while(arr[start]<pivot){
        start++;
    }
    while(arr[end]>pivot){
        end--;
    }
    swap(&arr[start],&arr[end]);
    }
    swap(&arr[high],&arr[start]);
    return start;
}

void quicksort(int arr[],int low,int high){
if(low<high){
    int mid=partition(arr,low,high);
    quicksort(arr,low,mid-1);
    quicksort(arr,mid,high);
}
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    quicksort(arr,0, N-1);
    printf("Sorted array is\n");
    printArray(arr, N);
}
