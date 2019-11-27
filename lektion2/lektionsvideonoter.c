#include <stdio.h>

lecture_number; /* Deklaration af variabel */

int lecture_number = 7; /* Initialisation af variabel */

lecture_number = 10; /* Assignment af en værdi til en variabel ( Overskriver 7 tallet) */ 





int n = 3;

lecture_number = 2*n-5  /*assignment med en regning */



double lecture_number = 7.0;  /* double kan indeholde kommatal */
const double pi = 3.14159 /* const kan ikke ændres, med en assignment. Hvis dette prøves gives fejl */



#define PI 3.14159  /*Symbolks konstant erstatter PI med tallet 3.14159 (En præpocessor) Skal stå før main */



int nummer1 = 1,  /* Initilastioner må sættes samme sådan her med "," imellem og variabler er case sensitive */
	Nummer1 = 2;




int lecture_number = 7;                 /* Måder at lægge til til en variaberl (Kan også gøres med minus) */

lecture_number = lecture_number + 1; 
lecture_number++;
lecture_number += 1;




									/*  Rene udtryk */



int day = 20;
int days_per_week = 7;

day + 1               /* operatore der ikke ændrer på variablen selv*/
day / days_per_week	  /* Division */	
day % days_per_week	  /* Modulo operatoren (finder resten efter division) */									





int x = 2,                      /* Printning af udregninger ved hjælp af placeholder variabler %d hvor de hver holder værdi fra den tilsvarence udtryk i reækkefølgen */
	y = 4,
    z = 6;

printf("1: %d, 2: %d x: %d\n",
x + y * 3 - z % 5,
y + z,
x );


int n = 2;
double x;

scanf("%d", &n);            /* scan for keyboard input med placeholder variabel for an den der skal skiftet. Denn skal matche typen af variabel. med "&" for at pointe til n eller x */
scanf("%lf", &x);

scanf("%d %lf %lf"; &n, &a, &b); /* Kan også slås sammen sådan her */

sr = scanf("%d %lf %lf"; &n, &a, &b);  /* antallet af korrekte konverteringer i int kan bruges til at tjekke om alt er skrevet ind ordentligt */
