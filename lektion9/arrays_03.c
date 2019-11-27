#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_function(double *a, double *b, double *merger);
void print_function(int number_of_elements, double *a);

int main(void){
  double array_a[] = {-23.2, -10.5, -5.4, 4.5, 7.8, 9.3},
         array_b[] = {-23.2, -10.3, -3.4, 8, 9.3}, 
         *merger_array;
  int array_merger_elements;

  array_merger_elements = (sizeof(array_a)+sizeof(array_b))/sizeof(double);
  
  merger_array = (double*) malloc(array_merger_elements*sizeof(double));

  merge_function(array_a, array_b, merger_array);
  
  print_function(array_merger_elements, merger_array);
  

  free(merger_array);
  return 0;
} 

void merge_function(double *a, double *b, double *merger){
  int i;
  double placeholder;

  for(i = 0; sizeof(a) > sizeof(b) ? i < sizeof(a) : i < sizeof(b); ++i){
    merger[i] = a[i] <= b[i] ? a[i] : b[i];
    placeholder = a[i] <= b[i] ? b[i] : a[i]; 
    merger[i+1] = placeholder;
  }


}

void print_function(int number_of_elements, double *a){
  int i;
  printf("Elements in merged array:");
  
  for (i = 0; i < number_of_elements; ++i){
    printf(" %.2f ", a[i]);
  }
  printf("\n");
}
