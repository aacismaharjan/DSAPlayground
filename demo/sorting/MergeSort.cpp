/*
 * Merge Sort in C 
 * Practice Session
 */
 
#include<stdio.h>

// Function to merge two sorted arrays
void merge(int arr[], int left, int mid, int right) {
	static int times = 0;
	
	printf("\nCalling=%d, left=%d, mid=%d, right=%d", times++, left, mid, right);
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	// Temporary arrays
	int L[n1], R[n2];
	
	// Copy data to temp arrays
	for(i=0; i<n1; i++)
		L[i] = arr[left + i];
	for(j=0; j<n2; j++) 
		R[j] = arr[mid + 1 + j];
		
	// Merge two arrays back into arr[left...right]
	i=0, j=0, k = left;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	
	// Copy remaining elements of L[]
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	// Copy remaining elements of R[]
	while(j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// Recursive function to sort the array
void mergeSort(int arr[], int left, int right) {
	if(left < right) {
		int mid = left + (right - left) / 2; // (7-0)/2 => 3.50 => 4
		
		printf("\nLeft=%d,Right=%d,Mid=%d", left, right, mid);
		
		// Sort first and second halves
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		
		// Merge the sorted halves
		merge(arr, left, mid, right);
	}
}

void printArray(int arr[], int size) {
	for(int i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Main function
int main() {
	int arr[] = {6, 3, 8, 5, 2, 7, 4, 1};
	int size = sizeof(arr) /sizeof(arr[0]);
	
	
	printf("Original array: ");
	printArray(arr, size);
	
	mergeSort(arr, 0, size-1);
	
	printf("Sorted array: ");
	printArray(arr, size);
	
	return 0;
}
