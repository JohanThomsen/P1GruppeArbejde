#include <stdio.h>
#define SECS_PR_MINUTE 60
#define SECS_PR_HOUR (60*60)

int main(void)
{
	 int seconds, minutes, hours, rest, secondsText;

	 int hoursPlural, minutesPlural, secondsPlural;                                               /* Assignmer mine variabler for udregningen */                                          
    
    printf("Input the number of seconds you want to convert\n");                    /* Prompter brugeren til at skrive */
    scanf("%d", &seconds);                                                          /* Scanner efter input og lægger værdien i variablen seconds */

    hours = seconds / SECS_PR_HOUR;
    rest = seconds % SECS_PR_HOUR;

    minutes = rest / SECS_PR_MINUTE;
    rest = seconds % SECS_PR_MINUTE;

    secondsText = rest;

    printf(" %d %d %d %d\n", hours, minutes, seconds, rest );


    if (hours >= 2 || hours == 0)
    {
    	hoursPlural = 1;
    } else{
    	hoursPlural = 0;
    }

    if (minutes >= 2 || minutes == 0)
    {
    	minutesPlural = 1;
    } else{
    	minutesPlural = 0;
    }

    if (secondsText >=2 || secondsText == 0)
    {
    	secondsPlural = 1;
    }else{
    	secondsPlural = 0;
    }

    if (secondsPlural)
    {
    	printf(" %d %d %d\n",hoursPlural, minutesPlural, secondsPlural);
    }

    
	return 0;
}