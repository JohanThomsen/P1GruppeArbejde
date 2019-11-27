#include <stdio.h>
#include <math.h>

//Laver prototyper for funktionerne 
void solveQuadraticEquation(double a, double b, double c);
double findDisc(double a, double b, double c);
double findRootOne(double discriminant, double a, double b);
double findRootTwo(double discriminant, double a, double b);
void charOverflow(char ch);


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
        do 
        {
            printf("Enter three coeficients, where the first is not zero:  (Type 0 0 0 to exit program)\n");
            scanres = scanf(" %lf %lf %lf", &a, &b, &c);
            if (scanres != 3)
            {
                charOverflow(ch);
            }
        }while (scanres != 3);
        // First i check if a equals 0, and if it isnt checking if ALL numbers are not zero, if they arent i solve the quadratic equation. 
        if (a != 0)
        {
            if ((b != 0 || c != 0))
            {            
                solveQuadraticEquation(a, b, c);   
            }
        }
        if (a == 0 && (b != 0 || c != 0))
        {
            printf("Please note that the first number cannot equal zero\n");
        }

            
    }while(a != 0 || b != 0 || c != 0);  // Checking for if all numbers arent 0, if they arent it loops through the program again.  
    
    printf("Exiting program\n");    
    
    return 0;
}

// This function checks for how many roots there are, and prints the results.
void solveQuadraticEquation(double a, double b, double c)
{
    double discriminant, root1, root2;

    discriminant = findDisc(a, b, c);

    if (discriminant < 0)
    {
        printf("There are no roots\n");
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
// Tihs function makes sure i do not get any false positives caused by chars.
void charOverflow(char ch)
{
    do 
    {
        scanf("%c", &ch);
    }while (ch != '\n');
}

