#include <stdio.h>
#include <math.h>

void ChangeExternalLocalVariable(double *pd);
void pointerAsInput(double *pd1, double *pd2, int *i);

int main(void)
{
    double d = 12.34;
    int    i = 56;

    double  *pd = &d,
            *pd1 = 0,
            *pd2 = 0;

    int     *pi = &i;

    ChangeExternalLocalVariable(&d);
    pointerAsInput(&d, &d, &i);

    printf("%lf %lf %lf\n", *pd , *pd1, *pd2);
    printf("%d\n", *pi);

    // pd = pi kan IKKE  lade sig gøre da de ikk er typesammenligneli



    return 0;
}

void ChangeExternalLocalVariable(double *pd)
{
    *pd += 5;
}

void pointerAsInput(double *pd1, double *pd2, int *i)
{

    double output1 = 0;
    double output2 = 0;

    //Pointer as input
    double input1 = *pd1;
    double input2 = *pd2;

    output1 = input1 + 6;
    output2 = input2 + 5;
    // Pointer as output
    *pd1 = output1;
    *pd2 = output2;
}