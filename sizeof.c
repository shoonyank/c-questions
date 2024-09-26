#include <stdio.h>
 
int main(void)
{
    short x;
    // type argument:
    printf("sizeof(float)          = %zu\n", sizeof(float));
    printf("sizeof(void(*)(void))  = %zu\n", sizeof(void(*)(void)));
    printf("sizeof(char[10])       = %zu\n", sizeof(char[10]));
	//  printf("sizeof(void(void))     = %zu\n", sizeof(void(void)));
	//  printf("sizeof(char[])         = %zu\n", sizeof(char[]));
 
    // expression argument:
    printf("sizeof 'a'             = %zu\n", sizeof 'a');
	//  printf("sizeof main            = %zu\n", sizeof main);
    printf("sizeof &main           = %zu\n", sizeof &main);
    printf("sizeof \"hello\"         = %zu\n", sizeof "hello");
    printf("sizeof x               = %zu\n", sizeof x);
    printf("sizeof (x+1)           = %zu\n", sizeof(x + 1));
}
