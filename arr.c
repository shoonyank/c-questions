#include"stdio.h"
int main(){
	
	int a=1;
	//int b = a++ + 4; // b = 1 + 4
	int b = ++a + 4; // b = 2 + 4
	printf("b=%d\na=%d", b, a);
	
	return 0;
}
