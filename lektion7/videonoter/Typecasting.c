#include <stdio.h>

int main(void) {

  char c;
  long int y;
  float x;
  double z;

  c = 'A' + 10;                  /* 'A' is char 65. 'A' + 10 is the character 'K'. c becomes 'K' */
  y = (long) (c);                /* y becomes 75L */
  x = (float) ((int) y + 1);     /* x becomes 76.0F in type float */
  z = (double) (x);              /* z becomes 76.0  in type double */

  printf("c: %c, y: %li, x: %f, z: %f", c, y, x, z);
  return 0;
}

