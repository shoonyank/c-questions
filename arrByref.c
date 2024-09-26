#include "stdio.h"
int sumArr(int*, int size);
int main(){
	int arr[] = {1,2,3,4,5};
	int *p;
	p = arr;
	int size = sizeof(arr)/sizeof(arr[0]);
	sumArr(p, size);
	for(int i=0;i<size;i++){
		printf("%d,", arr[i]);
	}
	
}
int sumArr(int *a, int size){
	for(int i=0;i<size; i++){
		printf("%d,", a[i]);
		a[i] = a[i] + 1;
	}
	return 1;
}

