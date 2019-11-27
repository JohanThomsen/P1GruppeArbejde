#include <stdio.h>

int main(void)
{
    int pyramidehojde,
        pyramidebund;

    printf("Please enter a non-negative integer for pyramid heigh\n");
    scanf("%d", &pyramidehojde);

    pyramidebund = ((pyramidehojde * 2));
    for (int i = 0; i <= pyramidebund; ++i)
    {
        for (int j = 0; j <= i && j > pyramidehojde; ++j)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}