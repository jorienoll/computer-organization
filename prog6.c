/*
 * Jorie Noll
 * reverse engineer method from machine code
 */

#include<stdio.h>

long decode2(long x, long y, long z){
    long r;
    y = y - z; //subq %rdx, %rsi
    x = x * y; //imulq %rsi, %rdi
    r = y; //movq %rsi, %rax
    r = r << 63; //salq $63, %rax
    r = r >> 63; //sarq $63, %rax
    r = r^x; //xorg %rdi, %rax
    return r; //ret
}

int main(void){
  printf("x=1, y=2, z=3 returns %ld\n", decode2(1,2,3));
  printf("x=3, y=2, z=1 returns %ld\n", decode2(3,2,1));
  printf("x=6, y=7, z=8 returns %ld\n", decode2(6,7,8));
  printf("x=8, y=7, z=6 returns %ld\n", decode2(8,7,6));

  return 0;
}
