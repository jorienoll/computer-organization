/*
 * Jorie Noll
 * addition that saturates to TMin or TMax
 */

#include <stdio.h>
#include <limits.h>

int staturating_add(int firstNumber, int secondNumber){
			int w = sizeof(firstNumber) << 3;
			int sum = firstNumber + secondNumber;

      int firstMSB = (unsigned) firstNumber >> (w - 1);
      int secondMSB = (unsigned) secondNumber >> (w - 1);
      int sumMSB = (unsigned) sum >> (w - 1);

      int posOverflow = ~firstMSB & ~secondMSB & sumMSB;
      int negOverflow = firstMSB & secondMSB & !sumMSB;

      return (-negOverflow & INT_MIN) + (-posOverflow & INT_MAX);
}

int main(void){
			int x = INT_MAX;
			int y = INT_MIN;

			printf("This program utilizes addition that saturates to TMin or TMax.\n");
			printf("x returns %d\n", staturating_add(x, x));
			printf("y returns %d\n", staturating_add(y, y));

			return 0;
}
