#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double trap(double a,double b,double n, double (*f)(double x));
double h(double a, double b, double n);
double sum_function(double a, double b, double n, double (*f)(double x));
double halfcircle(double x);
double sin_func(double x);

int main(void)
{
    double n =  0,                                                     /* Here i assign and initalize my variables, where n is how many trapezoids will be made */
           a = -2,                                                     /* and a, b, sin_a, and sin_b are the start and end points of the 2 functions            */
           b =  2,
       sin_a =  0, 
       sin_b =  3.14159,
         cap =  256;
 
    for (n = 2; n <= cap; n *= 2)
    {
        printf("The approximate area of the halfcircle when n is %0.1f is: %f\n", n, trap(a, b, n, &halfcircle)); 
    }
    printf("\n");       
    for (n = 2; n <= cap; n *= 2)
    {
        printf("The approximate area of the sin function when n is %0.1f is: %f\n", n, trap(sin_a, sin_b, n, &sin_func)); 
    }
    return 0;
}

double trap(double a, double b, double n, double (*f)(double x))
{
    return (h(a, b, n) / 2) * (f(a) + f(b) + 2 * (sum_function(a, b, n, f)));
}


double h(double a, double b, double n)
{
    return ((b) - (a)) / n;
} 

double sum_function(double a, double b, double n, double (*f)(double x))
{
    double sum = 0,
                 i,
          currentX,
          interval;
       
    interval = h(a, b, n);
    currentX = a;

    for (i = 1; i < n; ++i)
    {
        sum += f(currentX); 
        currentX += interval;
    }
    return sum;
}

double halfcircle(double x)
{
    return sqrt(4 - (x * x));
}

double sin_func(double x)
{
    return (x * x) * sin(x);
}