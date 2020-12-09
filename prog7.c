/*
 * Jorie Noll
 * reverse engineer a switch statement from machine code
 */

 long switch_prob(long x, long n) {
     long result = x;
     switch(n) {
         case 60:
             result *= 8;
             break;
         case 62:
             result *= 8;
             break;
         case 63:
             result = x;
             result >>= 3;
             break;
         case 64:
             result = x;
             result <<= 4;
             result = result - x;
             x = result;
             x = x * x;
             result = x + 75;
             break;
         case 65:
             x *= x;
             result = x + 75;
             break;
             default:
                result = x + 75;
     }
     return result;
 }

 int main(void){
   printf("x=3, n=65 returns %ld\n", switch_prob(3,65));
   printf("x=5, n=50 returns %ld\n", switch_prob(5,50));

   return 0;
 }
