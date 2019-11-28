#include <stdio.h>
#include <stdlib.h>

#define SENTINEL -1

int quotient(int dividend, int divisor);
int modulus(int dividend, int divisor);

int main(void){
  int dividend = 0, 
      divisor = 0, 
      scanres = 0;


  do {
    printf("Input a dividend and a divisor (integers only): ");
    scanres = scanf(" %d %d", &dividend, &divisor);
  
    if (scanres == 2 && dividend != SENTINEL && divisor != SENTINEL){
      printf("Dividend: %d, Divisor: %d\nQuotient: %d, Modulo: %d\n", dividend, divisor, 
                                                                      quotient(dividend, divisor), 
                                                                      modulus(dividend, divisor)
                                                                      );
    }
  } while (dividend != SENTINEL && divisor != SENTINEL);
  
 return 0;
}

int quotient(int dividend, int divisor){
  static int count = 0;

  if (divisor == 0){
    return 0;
  } else if (dividend >= divisor){
    ++count;
    return quotient(dividend - divisor, divisor);
  } else {
    return count;
  }
}

int modulus(int dividend, int divisor){

  if (divisor == 0){
    return 0;
  } else if (dividend >= divisor){
    return modulus(dividend - divisor, divisor);
  } else {
    return dividend;
  }
}
