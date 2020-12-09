/*
 * Jorie Noll
 * mask with least significant n bits set to 1
 * ex. n=6 --> 0x3F, n = 17 --> 0x1FFFF
 * assume 1 <= n <= w
 * */

#include <stdio.h>

int main(int argc, char **argv){
	printf("n=6 returns 0X%X\n", lower_one_mask(6));
	printf("n=17 returns 0X%X\n", lower_one_mask(17));

	return 0;
}

int lower_one_mask(int n){
	int mask = sizeof(int) << 3;
	int bits = -1;
	return (unsigned) bits >> (mask - n - 1) >> 1;
}
