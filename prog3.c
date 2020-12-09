/*
 * Jorie Noll
 *return 1 when x can be represented as an n-bit, 2's compliment
 *number; 0 otherwise assume 1 <= n <= 2
 */

#include <stdio.h>

int fits_bits(int x, int n){
    int shift = 33 + ~n;
    int left = x << shift;
    int right = left >> shift;
    return !(right ^ x);
}

int main(void){
    printf("Return 1 when x can be represented in an n-bit, \n2's compliment number; 0 otherwise.\n");
    printf("(x=2, n=2) returns %d\n", fits_bits(2, 2));
    printf("(x=-2, n=2) returns %d\n", fits_bits(-2, 2));
    printf("(x=2, n=3) returns %d\n", fits_bits(2, 3));
    printf("(x=5, n=3) returns %d\n", fits_bits(5, 3));
    printf("(x=-4, n=3) returns %d\n", fits_bits(-4, 3));
    printf("(x=-129, n=8) returns %d\n", fits_bits(-129, 8));
    printf("(x=-128, n=8) returns %d\n", fits_bits(-128, 8));
    printf("(x=128, n=8) returns %d\n", fits_bits(128, 8));

    return 0;
}
