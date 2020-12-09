/*
 * Jorie Noll
 * */
#include <stdio.h>

int evaluate(int x){
	unsigned int testOption1 = 0xf;
	unsigned int testOption2 = 0xffffffff;
  unsigned int testOption3 = 0xf0000000;
	int a = !((x & ~testOption2) | (~x & testOption2));
	int b = !((x & testOption2) | (~x & ~testOption2));
	int c = !(((x & testOption1) & ~testOption1) | (~(x & testOption1) & testOption1));
	int d = !(((x & testOption3) & ~0x0) | (~(x & testOption3) & 0x0));
	return (a || b || c || d);
}

int main(){
	//a
	printf("A evaluates to %d\n", evaluate(0xffffffff));
	//b
	printf("B evaluates to %d\n", evaluate(0x00000000));
	//c
	printf("C evaluates to %d\n", evaluate(0x0000000f));
	//d
	printf("D evaluates to %d\n", evaluate(0x0fffffff));
}
