#include <stdio.h>

int main(void)
{
    int n = 2; /* Assigner og initialiserer variablen n */
    double x; /* assigner variablen x */

    printf("n = %d, x = %f\n", n, x ); /*printer variablen via placeholders der lader dem blive vist" */

    printf("Enter n and x:\n");  /* Beder om inputs via tekst */   
    scanf("%d", &n);               /* Leder efter input for n via placeholderen d og pointer til n */
    scanf("%lf", &x);               /* same bare med lf og x */

    printf("n = %d, x = %f\n", n, x ); /* Printer de ny værdier med placeholders */

    return 0;
}