/*
 * Selection Sort in C 
 * Practice Session
 */
 
#include<stdio.h>

void selectionSort(int arr[], int n) {
	int i,j, minIndex, temp;
	
	// Traverse through all array elements
	for(i=0; i<n-1; i++) {
		minIndex = i;
		
		// Find the minimum element in the unsorted part
		for(j=i+1; j<n; j++) {
			if(arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		
		// Swap the found minimum element with the first element
		if(minIndex != i) {
			temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}

// Function to print the array
void printArray(int arr[],  int size) {
	for(int i=0; i<size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[]  = {64, 25, 12, 22, 11};
	int n = sizeof(arr) /sizeof(arr[0]);
	
	printf("Original Array: ");
	printArray(arr, n);
	
	selectionSort(arr, n);
	
	printf("Sorted Array: ");
	printArray(arr, n);
	
	return 0;
}
