#include"stdio.h"
#include"math.h"
int main(){
	int n = 7;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*n-1;j++){
			if(j==n-i+1|| j==n+i-1){
				printf("*");
			}else{
				printf(" ");
			}
		}
		
		printf("\n");
	}
	return 0;
}
// wap to display 
//	this is a backslash \
//	this is a double quote "
