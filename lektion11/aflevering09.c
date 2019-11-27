#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH_OF_KULOER             6
#define ANTAL_SPILLEKORT_I_ET_SPIL_KORT 55

enum kuloer {Kloer = 1, Ruder, Hjerte, Spar, joker};
enum vaerdi_kort {Es, To, Tre, Fire, Fem, Seks, Syv, Otte, Ni, Ti, Kneagt, Dame, Konge};


struct spillekort{
    int  kuloer;
    int  vaerdi;
};
typedef struct spillekort spillekort;

spillekort smart_function (int vaerdi, int kuloer);
char*      vaerdi_convert (int vaerdi);
int element_compare_random(const void *constPtr1, const void *constPtr2);
int element_compare_kuloer(const void *kuloer_a, const void *kuloer_b);
void deck_generator       (spillekort *et_spil_kort);
void print_funktion       (spillekort *et_spil_kort);
void bland_kort_og_print  (spillekort *et_spil_kort);
void sorter_kort_og_print (spillekort *et_spil_kort);

int main(void){
    spillekort* et_spil_kort = calloc(ANTAL_SPILLEKORT_I_ET_SPIL_KORT,  sizeof(spillekort)); 

    srand(time(NULL));

    deck_generator(et_spil_kort);

    bland_kort_og_print(et_spil_kort);

    sorter_kort_og_print(et_spil_kort);

    return 0;
}

void print_funktion(spillekort *et_spil_kort){
    int i;
    for(i = 0; i < ANTAL_SPILLEKORT_I_ET_SPIL_KORT; ++i){
        printf("%6s %s\n", et_spil_kort[i].kuloer == Kloer ? "Kloer" : et_spil_kort[i].kuloer == Ruder ? "Ruder" : et_spil_kort[i].kuloer == Hjerte ? "Hjerte" : et_spil_kort[i].kuloer == Spar ? "Spar" : "Joker",
                           i < 52 ? vaerdi_convert(et_spil_kort[i].vaerdi) : "");
    }
}

void bland_kort_og_print(spillekort *et_spil_kort){
    qsort(et_spil_kort, 52, sizeof(spillekort), element_compare_random); /* Shuffle */
    printf("Blandet spil Kort :\n");
    print_funktion(et_spil_kort);
}

void sorter_kort_og_print(spillekort *et_spil_kort){
    qsort(et_spil_kort, 52, sizeof(spillekort), element_compare_kuloer);
    printf("_____________________________________\n\nSorteret spil kort\n");
    print_funktion(et_spil_kort);
}

void deck_generator (spillekort *et_spil_kort){
    int i;
    for(i = 0; i < 13; ++i){
        et_spil_kort[i]    = smart_function(i+1, 1);
        et_spil_kort[i+13] = smart_function(i+1, 2);
        et_spil_kort[i+26] = smart_function(i+1, 3);
        et_spil_kort[i+39] = smart_function(i+1, 4);
    }
}

char* vaerdi_convert(int vaerdi){
    char* converted_vaerdi = (char *) calloc (8, (sizeof(char)));

    switch ((vaerdi) % 13)
    {
        case Es:
            converted_vaerdi = "Es";
            break;
        
        case To:
            converted_vaerdi = "To";
            break;

        case Tre:
            converted_vaerdi = "Tre";
            break;

        case Fire:
            converted_vaerdi = "Fire";
            break;
            
        case Fem:
            converted_vaerdi = "Fem";
            break; 
            
        case Seks:
            converted_vaerdi = "Seks";
            break;
            
        case Syv:
            converted_vaerdi = "Syv";
            break; 
        
        case Otte:
            converted_vaerdi = "Otte";
            break;

        case Ni:
            converted_vaerdi = "Ni";
            break;
        
        case Ti:
            converted_vaerdi = "Ti";
            break;

        case Kneagt:
            converted_vaerdi = "Kneagt";
            break;
            
        case Dame:
            converted_vaerdi = "Dame";
            break;                

        case Konge:
            converted_vaerdi = "Konge";
            break;
    }        

    return converted_vaerdi;
}   

spillekort smart_function(int vaerdi, int kuloer){
    spillekort genereret_kort;

        genereret_kort.kuloer = kuloer;
        genereret_kort.vaerdi = vaerdi; 
  
    return genereret_kort;

}

int element_compare_kuloer(const void *kuloer_a, const void *kuloer_b){
    
    int result;
    spillekort *spillekortA = (spillekort *)kuloer_a;
    spillekort *spillekortB = (spillekort *)kuloer_b;

    if(spillekortA->kuloer == spillekortB->kuloer){
        result = (spillekortA->vaerdi - spillekortB->vaerdi);
    } else {
        result = (spillekortA->kuloer - spillekortB->kuloer);
    }

  return result;
}

int element_compare_random(const void *constPtr1, const void *constPtr2){
    int result;

    if (rand() < RAND_MAX / 2)
    {
        result = -1;
    }
    else if (rand() > RAND_MAX /2)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

  return result;
}