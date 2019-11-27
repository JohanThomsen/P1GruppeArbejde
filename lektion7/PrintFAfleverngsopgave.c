#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double trap(double a,double b,double n);
double h(double a, double b, double n);
double f_a(double a);
double f_b(double b);
double sum_function(double n);
double halfcircle(double x);

int main(void)
{
    double n =  8;
    double a = -2; 
    double b =  2;
    double check;
    check = (b) - (a);
    printf("Check %f\n", check);

    printf("Result is %f\n", trap(a, b, n));
    return 0;
}

double trap(double a, double b, double n)
{
    return (h(a, b, n) / 2) * (f_a(a) + f_b(b) + 2 * (sum_function(n)));
}


double h(double a, double b, double n)
{
    double h;
    h = ((b) - (a)) / n;
    printf(" h is%f\n", h);
    return h;
} 

double f_a(double a)
{
    return halfcircle(a);
}
double f_b(double b)
{
    return halfcircle(b);
}

double sum_function(double n)
{
    double sum = 0;
    double   i = 1;
    double currenty;
    double interval;

    interval = 4 / n;
    currenty = -2;
    for (i = 1; i < n; ++i)
    {
        sum += halfcircle(currenty); 
        printf(" Sum is: %f\n", sum); 
        currenty += interval;
    }
    return sum;
}

double halfcircle(double x)
{
    double halfcircle;
    halfcircle = sqrt(4 - (x * x));
    printf("Halfcircle is :%f\n", halfcircle);
    return halfcircle;
}