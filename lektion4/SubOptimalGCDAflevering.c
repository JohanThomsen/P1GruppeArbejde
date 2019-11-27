#include <stdio.h>
#include <math.h>

int main(void)
{
    int     a,
            b,
        small,
          big,
    smallTemp,
      bigTemp,
      scanres;
    char   ch;

  /* Sørger for at jeg får 2 negative heltal */
    do 
    {
        printf("Enter two non-negative integers, to find their greatest common divisor: \n");
        scanres = scanf(" %d %d", &a, &b);
        if (scanres != 2)
        {
            do 
            {
                scanf("%c", &ch);
            }while (ch != '\n');
        }
    }while ((scanres != 2) || (a <= 0 || b <= 0));

    // Sorterer tallene så jeg ved hvilket tal er det største
    small = a <= b ? a : b;
    big   = a <= b ? b : a;

    /* Modulo med det lille tal først, tjek om det giver nul. Så modulo med det lille tal divideret med 2, tjek om det giver modulo, Så modulo med det lille tal divideret med, tjek om det giver nul. OSV.
    Når dette giver nul, stopper loopet og det printes. */
    int dividor = 1;

    while (bigTemp != 0)
    {
        smallTemp = small / dividor;
        bigTemp   = big % smallTemp;
        dividor++;
    }

    printf("The greatest common divisor is: %d\n", smallTemp);
    
    return 0;
}