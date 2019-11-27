#include <stdio.h>

typedef enum days {sunday, monday, tuesday, wednesday, thursday, 
                   friday, saturday} days;

days  next_day_of(days  d){
  return ( days ) (((int) d + 1) % 7);
}  

void prnt_day(days  d){
  switch (d) {
    case sunday: printf("Sunday");
       break;
    case monday: printf("Monday");
       break;
    case tuesday: printf("Tuesday");
       break;
    case wednesday: printf("Wednesday");
       break;
    case thursday: printf("Thursday");
       break;
    case friday: printf("Friday");
       break;
    case saturday: printf("Saturday");
       break;
  }
}   

int main(void){
  
  days  day1 = saturday,  another_day;
  int i;

  printf("Day1 is %d\n", day1);

  printf("Day1 is also "); prnt_day(day1); printf("\n");

  another_day = day1;
  for(i = 1; i <= 3; i++)
    another_day = next_day_of(another_day);
  
  printf("Three days after day1: ");  prnt_day(another_day); 
  printf("\n");

  return 0;
}    