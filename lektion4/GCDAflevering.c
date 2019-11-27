
#include <stdio.h>
#include <math.h>

int main(void)
{
    int       a,
              b,
        scanres;
    char     ch;    

      do {
    printf("Please enter two non-negative integers, to find their greatest common divisor: \n");
    scanres = scanf(" %d %d", &a, &b);
    if (scanres != 2){
      do
        scanf("%c", &ch);
      while (ch != '\n');
    }
  } while ((scanres != 2) || (a <= 0 || b <= 0));

    while(a != b)
    {
        if (b > a)
        {
            b -= a;
        }else{
            a -= b;
        }
    }
    
    printf("%d\n", a);

    return 0;
}