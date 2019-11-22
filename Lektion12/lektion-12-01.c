#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LGT 50

typedef struct{
  char fornavn[MAX_NAME_LGT];
  char efternavn[MAX_NAME_LGT];
  char vejnavn[MAX_NAME_LGT];
  int vejnummer;
  int postnummer;
  char bynavn[MAX_NAME_LGT];
} person;

int element_compare(const void* a, const void* b);

int main(void){
  FILE *ifp = fopen("adresser.txt", "r");
  person person_array[50];
  char *current_string = (char*)calloc(200, sizeof(char));
  int i = 0;

  if (ifp != NULL){
    current_string = fgets(current_string, 200, ifp);
    while (current_string != NULL){
      printf("current_string: %s\n", current_string);
      sscanf(current_string, 
             " %[a-zA-Z]"
             " %[a-zA-Z],"
             " %[^0-9]"
             " %d,"
             " %d"
             " %[a-zA-Z].",
             person_array[i].fornavn,
             person_array[i].efternavn,
             person_array[i].vejnavn,
             &person_array[i].vejnummer,
             &person_array[i].postnummer,
             person_array[i].bynavn
             );
      printf("fornavn: %s, efternavn: %s, vejnavn: %s, vejnummer: %d, postnummer: %d, bynavn: %s\n\n",
              person_array[i].fornavn,
              person_array[i].efternavn,
              person_array[i].vejnavn,
              person_array[i].vejnummer,
              person_array[i].postnummer,
              person_array[i].bynavn
              );
      current_string = fgets(current_string, 200, ifp);
      ++i;
    }
  } else {
    printf("Did not get to open the desired document\n");
  }

  qsort(person_array, 10, sizeof(person), element_compare);
  
  putchar('\n'); 
  printf("By      | Navn\n");
  for(i = 0; i < 10; ++i){
    printf("%-8s| %s\n", person_array[i].bynavn, person_array[i].efternavn);
  }
  putchar('\n'); 

  return 0;
}

int element_compare(const void* a, const void* b){
  return strcmp((*(person*)a).efternavn, (*(person*)b).efternavn);
}
