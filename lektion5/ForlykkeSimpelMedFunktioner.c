#include <stdio.h>
#include <math.h>

int sumForm(int n);
int sumIter(int n);

int main(void)
{
    int   n = 0,
        sum = 0,
 sumFraIter = 0,
 sumFraForm = 0;

    printf("Giv mig et tal du vil finde summen af:\n");
    scanf("%d", &n);

    printf("Summen af talrækken fra den iterære løkke er %d\n", sumIter(n));

    printf("Summen af talrækken fra formlen er %d\n", sumForm(n));

    return 0;
}


int sumIter(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; ++i)
    {
        sum += i;
    }
    return sum;
}

int sumForm(int n)
{ 
    return n*(n + 1)/2;
}