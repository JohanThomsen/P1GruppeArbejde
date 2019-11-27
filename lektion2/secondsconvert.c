#include <stdio.h>
#define MINUTES 60
#define HOURS 3600
#define DAYS 86400
#define WEEKS 604800

int main(void)
{
    int seconds, minutes, hours, days, weeks, rest;                                 /* Assignmer mine variabler for udregningen */                                          
    
    printf("Input the number of seconds u want to convert\n");                      /* Prompter brugeren til at skrive */
    scanf("%d", &seconds);                                                          /* Scanner efter input og lægger værdien i variablen seconds */

    weeks = seconds / WEEKS;                                                        /* Lave udregningen for hvor mange uger, dage osv det giver ved hjælp af division og modulo */
    rest = seconds % WEEKS;

    days = rest / DAYS;
    rest = seconds % DAYS;

    hours = rest / HOURS;
    rest = seconds % HOURS;

    minutes = rest / MINUTES;
    rest = seconds % MINUTES;

                                                                                                                                            /* Printer resultatet til brugeren */
    if (seconds >= WEEKS *2)                                                                                                                /* Prøver at eleminere unødvendige ord, så som hvis der er 0 uger bliver uger ikke nævnt */
    {
        printf("%d seconds equal %d weeks, %d days, %d hours, %d minutes and %d seconds\n",seconds, weeks, days, hours, minutes, rest);     /* Prøver også på at fikse grammatiske fejl så et 1 tal står i ental, dette lykkedes dog ikke helt da jeg ikke kunne se en måde at gøre dette for variabler der ikke er den første uden at lave endnu flere grimme else if statements */
    }else if (seconds > WEEKS && seconds >= DAYS *2)
    {                                                                                                                                       /* Derfor stoppede jeg her hvor det dog stadig er grammatisk korrekt det meste af tiden */
        printf("%d seconds equal %d week, %d days, %d hours, %d minutes and %d seconds\n",seconds, weeks, days, hours, minutes, rest);       /* Prøvede også at leve dette i en switch men kunne ikke helt finde ud af hvordan sådan en virker */
    }else if (seconds >= DAYS && seconds >= HOURS *2)
    {
        printf("%d seconds equal %d day, %d hours, %d minutes and %d seconds\n",seconds, days, hours, minutes, rest);                        
    }else if (seconds >= HOURS && seconds >= MINUTES *2)
    {
        printf("%d seconds equal %d hour, %d minutes and %d seconds\n",seconds, hours, minutes, rest);
    }else if (seconds >= MINUTES && seconds * 2 )
    {
        printf("%d seconds equal %d minute and %d seconds\n",seconds, minutes, rest);
    }else if (seconds >= 1)
    {
        printf("%d seconds equal %d seconds\n",seconds, rest);
    }else if (seconds == 1)
    {
        printf("%d second equal %d second\n",seconds, rest);
    }else if (seconds == 0)
    {
        printf("You have entered 0");
    }

    return 0;
}