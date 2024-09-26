#include"stdio.h"
int increment(int a){
	printf("a = %d\n",a);
	a= a+1;
	return a;
}
int main(){
	int x=2,y=3;
	printf("a = %d\n",increment(x));
	return 0;
}
