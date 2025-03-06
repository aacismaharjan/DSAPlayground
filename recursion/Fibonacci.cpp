#include<stdio.h>


// n = 7
// 1 1 2 3 5 8 13 
int fibo(int n) {
	if(n<= 1) {
		return n;
	}
	
	return fibo(n-1) + fibo(n-2);
}


int main() {
	fibo(10);
	return 0;
}
