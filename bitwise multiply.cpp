#include"stdio.h"
int main(){
	int x=2;
	for(int i=0;i<10;i++){
		printf("%d * %d = %d\n", x, i+1, x<<i);
	}
	return 0;
}
