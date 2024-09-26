#include"stdio.h"
int main(){
	int x=2;
	for(int i=1;i<=10;i++){
		printf("%d * %d = %d\n", x, i, (x<<1)*((i-1)+1)>>1);
	}
	return 0;
}
