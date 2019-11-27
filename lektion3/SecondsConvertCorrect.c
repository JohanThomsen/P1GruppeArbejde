#include <stdio.h>
#define SECS_PR_MINUTE 60
#define SECS_PR_HOUR (60*60)

int main(void)
{   
    int inputSeconds, minutes, hours, seconds, rest;                                                     // Assigner mine variabler for udregningen.                                          

    printf("Input the number of seconds you want to convert. Then press 'ENTER'.\n");                    // Prompter brugeren til at skrive.
    scanf("%d", &inputSeconds);                                                                          // Scanner efter input og lægger værdien i variablen inputSeconds.
 
    hours = inputSeconds / SECS_PR_HOUR;
    rest = inputSeconds % SECS_PR_HOUR;

    minutes = rest / SECS_PR_MINUTE;
    rest = inputSeconds % SECS_PR_MINUTE;

    seconds = rest;

    if (inputSeconds >= 1)                                                                               //Tjekker om der bliver skrevet et validt tal, og hvis der gør printer jeg starten på min sætning.
    {
        printf(inputSeconds == 1 ? "%d second equals : " : "%d seconds equals : ", inputSeconds );
    }else
    {
        printf("You have entered an invalid number");
    }                                                        

    if (hours >= 1)                                                                                      // Kører igennem alle mulige situationer ved hjælp af if statements, og ternære operatore.                                    
    {
        printf("%d %s",hours, hours > 1 ? "hours" : "hour" );                                            // Med disse fylder jeg sætningen ud, med de grammatisk korrekte former for ordene og med , and og punktum.  
        printf(minutes != 0 && seconds != 0 ? ", " : (minutes == 0 && seconds == 0 ? "." : " and "));
    }

    if (minutes >= 1)
    {
        printf("%d %s",minutes, minutes > 1 ? "minutes" : "minute" );
        printf(seconds != 0 ? " and " : ".");
    }

    if (seconds >= 1)
    {
        printf("%d %s",seconds, seconds > 1 ? "seconds." : "second.");
    }

    printf("\n");                                                                                        // Laver et line break så det bliver pænt i terminalen.

    return 0;
}