#include <stdio.h>
#include <math.h>

int main(void)
{
    int population     =  9870,
        year_counter   =     0,
        population_max = 30000;

    while(population <= population_max)
    {
        printf("In year %d, the population is %d\n", year_counter, population );
        population *= 1.10;
        year_counter++;
    }

    printf("The final population is %d which took %d years\n", population, year_counter);
    return 0;
}