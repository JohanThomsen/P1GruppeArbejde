#include <stdio.h>

/* Define constants for seconds in one whole minute and one whole hour */
#define SECONDS_IN_A_MINUTE 60
#define SECONDS_IN_AN_HOUR 3600

void hours_minutes_seconds(int input_sec, int *p_seconds, int *p_minutes, int *p_hours);


int main(void) 
{
    int seconds, minutes, hours;
 
    /* Declare variabels used
     * Initializing input with the value zero ensure that an illegal input value (eq. a character or a sentence) 
     * will not return a random value but zero instead, thus failing the positive integer check in the first if-statement */
    int input_sec=0;
    
    printf("\nInput a whole number of seconds to be converted: ");
    scanf("\n %d", &input_sec);
    printf("\nInput = %d Seconds\n\n", input_sec);

    hours_minutes_seconds(input_sec, &seconds, &minutes, &hours);

    if (hours > 0) {
      printf("%d %s%s", hours, hours == 1 ? "Hour" : "Hours", seconds && minutes ? "," : minutes ^ seconds ? " and" : "\n" );
    }
    if (minutes > 0) {
      printf(" %d %s%s", minutes, minutes == 1 ? "Minute" : "Minutes", seconds ? " and" : "\n" );
    }
    if (seconds > 0) {
      printf(" %d %s\n", seconds, seconds == 1 ? "Second" : "Seconds"); 
    }
     
    /* Check if input is a positive integer */
   
    return 0;
}

void hours_minutes_seconds(int input_sec, int *p_seconds, int *p_minutes, int *p_hours) {
    if (input_sec > 0)
    {
      *p_seconds = input_sec % SECONDS_IN_A_MINUTE;
      *p_minutes = input_sec % SECONDS_IN_AN_HOUR / SECONDS_IN_A_MINUTE;
      *p_hours = input_sec / SECONDS_IN_AN_HOUR;

    }

    else {
      printf("Input was %d, however a positive integer was expected\n", input_sec);
    }

}

