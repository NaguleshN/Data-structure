
#include <stdio.h>
#include <stdlib.h>



void swap(int* a, int* b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int arr[],int N,int i){

int largest=i;
int left=2*i+1;
int right=2*i+2;

if(left<N&&arr[left]>arr[largest]){
    largest=left;
}
if(right<N&&arr[right]>arr[largest]){
    largest=right;
}

if(i!=largest){
    swap(&arr[largest],&arr[i]);
    heapify(arr,N,largest);

}

}

void heapSort(int arr[],int N){

for(int i=(N/2)-1;i>=0;i--){
    heapify(arr,N,i);
}


for(int i=N-1;i>=0;i--){
    swap(&arr[i],&arr[0]);
    heapify(arr,i,0);
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
    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}


/*
// Heap Sort in C

#include <stdio.h>

// Function to swap the position of two elements
void swap(int* a,int* b){
int temp= *a;
*a =*b;
*b=temp;
}



// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[],int N,int i){

int largest=i;
int left=2*i+1;
int right=2*i+2;

if(left<N&&arr[left]>arr[largest]){
    largest=left;
}
if(right<N&&arr[right]>arr[largest]){
    largest=right;
}

if(i!=largest){
    swap(&arr[largest],&arr[i]);
    heapify(arr,N,largest);

}

}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build max heap
	for (int i = N / 2 - 1; i >= 0; i--)

		heapify(arr, N, i);

	// Heap sort
	for (int i = N - 1; i >= 0; i--) {

		swap(&arr[0], &arr[i]);

		// Heapify root element
		// to get highest element at
		// root again
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver's code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);
}

// This code is contributed by _i_plus_plus_.
*/
