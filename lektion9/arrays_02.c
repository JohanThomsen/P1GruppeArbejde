#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_EYES_ON_DIE 6
#define NUMBER_OF_ROWS_IN_YATZY 15

int* roll_multiple_dice(int number_of_dice_to_use, int *a);
int roll_die(void);
void print_function(int number_of_elements, int *a);
int input_data(void);


int main(void){
    int *a;
    int n;

    n = input_data();
    a = (int *) malloc (n*(sizeof(int)));

    if (a == NULL){
        printf("Didn't get the memory we wanted. Now terminating");
        return EXIT_FAILURE;
    }
  
    srand(time(NULL));

    for (int i = 0; i < NUMBER_OF_ROWS_IN_YATZY; ++i)
    {
        printf("%d\n", i);
    }

    roll_multiple_dice(n, a);

    print_function(n, a);


  
  
    free(a);
    return 0;
}


int* roll_multiple_dice(int n, int *a){
  int i;
  
  for (i = 0; i < n; ++i){
    a[i] = roll_die();
  }

  return a;
}

int roll_die(void){
   return (rand() % MAX_EYES_ON_DIE) + 1;  
}


void print_function(int number_of_elements, int *a){
    int i;

    for (i = 0; i < number_of_elements; ++i){
        printf("Roll %2d show %2d\n", i+1, a[i]);
    }
}

int input_data(void){
    int n;
    printf("Please input the nmber of dice you want to play with :\n");
    scanf(" %d", n);
    return n;
}


