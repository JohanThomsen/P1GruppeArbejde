#include <stdio.h>

#define EURO    0.89
#define DKK     6.66
#define ROUBLES 66.43
#define YEN     119.9

void omregnings_funktion(double input_value);

int main(void) {
  double input_value;

  printf("Skriv et beløb i dollars: \n");
  scanf(" %lf", &input_value);

  omregnings_funktion(input_value);

  return 0;
}

void omregnings_funktion(double input_value){
  double dollar_value = input_value;
  int counter;

  printf("Euro | Kroner | Rubler | Yen\n");
  for (counter = 1; counter <= 100; ++counter){
    printf("%d $ = %0.2lf Euro | %0.2lf DKK | %0.2lf Rubler | %0.2lf Yen\n", counter, counter*EURO, counter*DKK, counter*ROUBLES, counter*YEN);
  }
  printf("\n\n%0.2lf dollars is \n %0.2lf Euro\n %0.2lf Kroner\n %0.2lf Rubler\n %0.2lf Yen", dollar_value, dollar_value*EURO, dollar_value*DKK, dollar_value*ROUBLES, dollar_value*YEN);
}

