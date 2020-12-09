/*
 * Jorie Noll
 * determine whether the arguments can be subtracted without overflow
 * returns 1 if the computation does not overflow
 */

#include <stdio.h>
#include <limits.h>

int x = INT_MIN;
int y = INT_MAX;

int main(void){
	printf("Determines whether arguments can be subtracted without overflow.\nReturns 1 if computation does not overflow, returns 0 if it does overflow.\n");
	printf("x - 1 returns %d\n", tsub_ok(x,1));
	printf("x - (-1) returns %d\n", tsub_ok(x,-1));
	printf("x - 2 returns %d\n", tsub_ok(x,2));
	printf("x - (-2) returns %d\n", tsub_ok(x,-2));
	printf("y - 1 returns %d\n", tsub_ok(y,1));
	printf("y - (-1) returns %d\n", tsub_ok(y,-1));
	printf("y - 2 returns %d\n", tsub_ok(y,2));
	printf("y - (-2) returns %d\n", tsub_ok(y,-2));

	return 0;
}

int tsub_ok(int x, int y){
	int negOverflow = ((x - y) & INT_MIN) && !(x & INT_MIN) && (y & INT_MIN);
	int posOverflow = !((x - y) & INT_MIN) && (x & INT_MIN) && !(y & INT_MIN);

	return negOverflow || posOverflow;
}

int asturating_add(int x, int y);
