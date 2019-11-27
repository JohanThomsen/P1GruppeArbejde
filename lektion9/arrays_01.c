#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int element_compare(const void *ip1, const void *ip2);

int main(void){
  int i;
  double *a;

  srand(time(NULL));

  a = (double *) malloc (MAX*(sizeof(double)));


  if (a == NULL){
    printf("Didn't get the memory we wanted. Now terminating");
    return EXIT_FAILURE;
  }

  for (i = 0; i < MAX ; ++i){
    a[i] = rand();
    printf("%.2f\n ", a[i]);
  }
  printf("\n");
  
  qsort(a, MAX, sizeof(double), element_compare);

  for (i = 0; i < MAX ; ++i){
    printf("%.2f\n ", a[i]);
  } 
  free(a);
  return 0;
}

int element_compare(const void *ip1, const void *ip2){
  int result;
  double *ipi1 = (double *)ip1, 
      *ipi2 = (double *) ip2;

  if (*ipi1 < *ipi2)
     result = -1;
  else if (*ipi1 > *ipi2)
     result = 1;
  else
     result = 0;

  return result;
}



