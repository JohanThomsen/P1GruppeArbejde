#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

enum forret  {guacamole,         tarteletter,  lakserulle,      graeskarsuppe};
enum hovedret{gyldenkal,         hakkebof,     gullash,         forloren_hare};
enum dessert {pandekager_med_is, gulerodskage, chokolademousse, citronfromage};

void maaltid();
void current_forret(enum forret random);
void current_hovedret(enum hovedret random);
void current_dessert(enum dessert random);
int roll_die(void);

int main(void)
{
    srand(time(NULL));

    int i;
    for (i = 0; i < 25; ++i)                    // Kører igennem maaltid 25 gange
    {
        maaltid();
    }
    return 0;
}

void maaltid()
{
    current_forret((enum forret) roll_die());      // typecaster mit random roll til den ønskede enum
    current_hovedret((enum hovedret) roll_die());
    current_dessert((enum dessert) roll_die());
}

void current_forret(enum forret random)                             // Bruger det tilfældeige tal i en switch 
{
    switch(random)                                                  //igennem enummen for at printe det rigtige
    {
        case guacamole:    printf("|Guacamole     |");break; 
        case tarteletter:  printf("|tarteletter   |");break;
        case lakserulle:   printf("|lakserulle    |");break; 
        case graeskarsuppe:printf("|graeskarsuppe |");break;
    }    
}

void current_hovedret(enum hovedret random)
{
    switch(random)
    {
        case guacamole:    printf(" gyldenkal     |");break;
        case tarteletter:  printf(" hakkebof      |");break;
        case lakserulle:   printf(" gullash       |");break;
        case graeskarsuppe:printf(" forloren hare |");break;
    }    
}

void current_dessert(enum dessert random)
{
    switch(random)
    {
        case guacamole:     printf(" Pandekager med is|\n");break;
        case tarteletter:   printf(" gulerodskage     |\n");break;
        case lakserulle:    printf(" chokolademousse  |\n");break;
        case graeskarsuppe: printf(" citronfromage    |\n");break;
    }    
}

int roll_die(void)                                                  //Finder et tilfældigt tal imellem 0 og 4
{
    return rand() % 4;
}