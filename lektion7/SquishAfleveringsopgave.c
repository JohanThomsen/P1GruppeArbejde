#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Prototypes of the functions used */
double trap(double a,double b,double n, double (*f)(double x));
double h(double a, double b, double n);
double sum_function(double a, double b, double n, double (*f)(double x));
double halfcircle(double x);
double sin_func(double x);

/* The main function passes n, and either a,b, or sin_b,sin_a, and also a function pointer to either the halfcircle function or the sin function, depending on which function is passed on.
 * It then prints the returned result for values n = 2, 4, 8, 16, 32, 64 and 128. */
int main(void){
    double n =  0, a = -2, b =  2, sin_a =  0, sin_b =  3.14159, cap =  128;
 
    for (n = 2; n <= cap; n *= 2){
        printf("The approximate area of the halfcircle when n is %0.1f is: %0.2f\n", n, trap(a, b, n, &halfcircle)); 
    }
    printf("\n");       
    for (n = 2; n <= cap; n *= 2){
        printf("The approximate area of the sin function when n is %0.1f is: %0.2f\n", n, trap(sin_a, sin_b, n, &sin_func)); 
    }
    return 0;
}

/* Input : Doubles a, b, n and a function f
 * Output: the approximate area under a given function
 * Method calling the function h, to find the number of trapezoids, then a different function which it finds the approxiamte area under,
 * by creating n number of trapezoids and finding the area of these */
double trap(double a, double b, double n, double (*f)(double x)){
    return (h(a, b, n) / 2) * (f(a) + f(b) + 2 * (sum_function(a, b, n, f)));
}

/* Input  : doubles a, b and n
 * Output : double h, which is used in the trapezoidal function, which is the length of n intervals in the function */ 
double h(double a, double b, double n){
    return ((b) - (a)) / n;
} 

/* Input : doubles, a, b, n, and a function f
 * Output: the sum of all trapezoids except for the first and last
 * Method: Calling the h function to find how much to move the x value, in the for loop,
 * which then finds by value of function f, for each x value (which there are n - 2 of) in the for loop */
double sum_function(double a, double b, double n, double (*f)(double x)){
    double sum = 0, currentX, interval;
       
    interval = h(a, b, n);
    
    for (currentX = (a + interval); currentX <= (b - interval); currentX += interval){
        sum += f(currentX);     
    }
    return sum;
}

/* Input : double x
 * Output: the value of the function for a halfcircle with radius 2, of the given x */
double halfcircle(double x){
    return sqrt(4 - (x * x));
}

/* Input : double x
 * Output: the value of the sin function of the given x */
double sin_func(double x){
    return (x * x) * sin(x);
}