#include<stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
	int i,j, temp;
	for(i=0; i < n-1; i++) {
		// Last i elements are already sorted
		for(j=0; j< n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				// Swap the elements
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}


// Function to print the array
void printArray(int arr[], int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("Original array: \n");
	printArray(arr, n);
	
	bubbleSort(arr, n);
	
	printf("Sorted array: \n");
	printArray(arr, n);
	
	return 0;
}
