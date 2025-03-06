#include<stdio.h>

void TOH(int n, char source, char destination, char auxiliary) {
	if (n==1) {
		printf("[DISK %d] %c -> %c \n", n, source, destination);
		return;
	}
	TOH(n-1, source, auxiliary, destination); 
	printf("[DISK %d] %c -> %c \n", n, source, destination); 
	TOH(n-1, auxiliary, destination, source); 
	
}


int main() {
	TOH(3, 'A', 'C', 'B');
	return 0;
}

