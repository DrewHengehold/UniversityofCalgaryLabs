/* prog_two.c
 * ENSF 337 Lab 4 Exercise  E
 *
 */

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include "read_input.h"

#define SIZE 50

int main(void)
{
  double n = 0;
  char digits[SIZE];  

  int y = EOF;
  
  while (1)
    {
      printf("\n\nEnter a value or press Ctrl-D to quit: ");
      y = read_real(digits, SIZE, &n);
  
      if(y == 1)
          if(fmod(n,1) == 0){printf("\nYour integer value is: %d", (int)n);}
          else{printf("\nYour double value is: %lf", n);}
      else if(y == EOF){
	printf("\nGood Bye.\n");
	break;
      }
      else
	printf("\n%s is an invalid integer.", digits);
    }
    
  return 0;
}
