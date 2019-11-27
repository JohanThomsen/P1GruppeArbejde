#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double trap(double a,double b,double n, double (*f)(double x));
double h(double a, double b, double n);
double sum_function(double a, double b, double n);
double halfcircle(double x);

int main(void)
{
    double n =     128;
    double a =       0; 
    double b = 3.14159;

    printf("The approximate area is: %f\n", trap(a, b, n, &halfcircle));
    return 0;
}

double trap(double a, double b, double n, double (*f)(double x))
{
    return (h(a, b, n) / 2) * (f(a) + f(b) + 2 * (sum_function(a, b, n)));
}

double h(double a, double b, double n)
{
    return ((b) - (a)) / n;
} 

double sum_function(double a, double b, double n)
{
    double sum = 0,
             i = 1,
          currentX,
          interval,
           BA_Diff;

    BA_Diff = (b) - (a);        
    interval = BA_Diff / n;
    currentX = a;

    for (i = 1; i < n; ++i)
    {
        sum += halfcircle(currentX); 
        currentX += interval;
    }
    return sum;
}

double halfcircle(double x)
{
    return (x * x) * sin(x);
}