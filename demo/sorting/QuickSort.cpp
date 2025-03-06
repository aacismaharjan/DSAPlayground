/*
 * QuickSort in C 
 * Practice Session
 */
 #include<stdio.h>
 
 void swap(int *a, int *b)  {
 	int temp = *a;
 	*a = *b;
 	*b = temp;
 }
 
 
 // 0 , 6
 int partition(int arr[], int low, int high) {
 	// pivot = 2 (last element)
 	int pivot = arr[high];
 	
 	// i = 0-1 => -1 (negative)
 	int i = low -1;
 	
 	// for j=0; j<6; j++
 	for(int j=low; j<high; j++) {
 		// 8 < 2 (false), 3 < 2 (false), 1 < 2 (true), 7 < 2 (false), 0 < 2 (true)
 		// 10 < 2 (false) finally j=5
 		if(arr[j] < pivot) {
 			i++; // i = 0, i=1,
 			
 			 // swap(&arr[0], &arr[2]) => {1, 3, 8, 7, 0, 10, 2}
 			 // swap(&arr[1], &arr[4]) => {1, 0, 8, 7, 3, 10, 2}
 			swap(&arr[i], &arr[j]);
		 }
	 }
	 // swap(&arr[2], &arr[6]) => {1, 0, 2, 7, 3, 10, 8}
	 swap(&arr[i+1], &arr[high]);
	 
	 // return 2
	 return (i+1);
 }
 
 // 0, 6
 void quickSort(int arr[], int low, int high) {
 	
 	if(low < high) {
 		int pi = partition(arr, low, high);
 		
 		// Recursively sort elements before and after partition
 		quickSort(arr, low, pi-1);
 		quickSort(arr, pi + 1, high);
	 }
 }
 
 
 void printArray(int arr[], int n) {
 	int i=0;
 	for(i=0; i<n; i++) {
 		printf("%d ", arr[i]);	
	}
 }
 
 int main() {
 	int arr[] = {8,3,1,7,0,10,2};
 	int n = sizeof(arr) / sizeof(arr[0]);
 	
 	printf("Original Array: ");
 	printArray(arr, n);
 	
 	quickSort(arr,0, n-1); // 0, 6
 	
 	printf("Sorted Array: ");
 	printArray(arr, n);
 	return 0;
 }
