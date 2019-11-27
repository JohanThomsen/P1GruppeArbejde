#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    double array[] = {1, 2, 3, 4, 5, 6};

    int arraysize;

    arraysize = sizeof(array) / sizeof(double);

    printf("%d\n", arraysize);

    return 0;
}