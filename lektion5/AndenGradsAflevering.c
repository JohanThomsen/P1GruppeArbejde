#include <stdio.h>
#include <math.h>

void solveQuadraticEquation(double a, double b, double c);
double findDisc(double a, double b, double c);
double findRootOne(double discriminant, double a, double b);
double findRootTwo(double discriminant, double a, double b);

int main(void) 
{
    double a = 0,
           b = 0,
           c = 0;
    int  scanres;
    char      ch;
    // Making sure i get the correct input, by weeding out all chars, and making sure that atleast one of the doubles does not equal 0.
    do 
    {
        printf("Enter three coeficients, where atleast one is not zero: \n");
        scanres = scanf(" %lf %lf %lf", &a, &b, &c);
        if (scanres != 3)
        {
            do 
            {
                scanf("%c", &ch);
            }while (ch != '\n');
        }
    }while ((scanres != 3) || (a == 0 && b == 0 && c == 0));

    solveQuadraticEquation(a, b, c);

    return 0;
}

// This function checks for how many roots there are, and prints the results.
void solveQuadraticEquation(double a, double b, double c)
{
    double discriminant, root1, root2;

    discriminant = findDisc(a, b, c);

    printf("The discriminant is : %lf\n", discriminant);

    if (discriminant < 0)
    {
        printf("Which means that there are no roots\n");
    }
    else if (discriminant == 0)
    {
        printf("Which gives one root: %lf\n", findRootOne(discriminant, a, b));
    }
    else
    {
        printf("Which gives two roots: %lf and %lf\n", findRootOne(discriminant, a, b), findRootTwo(discriminant, a, b));
    }

}   

// These 3 functions do the calculations in the formula. First function finds the discrimant, and the next 2 find the 2 possible roots.
double findDisc(double a, double b, double c)
{
    return b * b - 4 * a * c;
}
double findRootOne(double discriminant, double a, double b)
{
    return (-b + sqrt(discriminant))/(2*a);
}

double findRootTwo(double discriminant, double a, double b)
{
    return (-b - sqrt(discriminant))/(2*a);
}