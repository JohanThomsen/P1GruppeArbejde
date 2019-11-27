#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
//#include "primes.h"
int is_prime(int i);
int number_of_primes(int);

int main(void)
{   
    int primes = 0,
             i = 0; 

    primes = number_of_primes(1000000);
    
    printf("%d\n", primes);         

    return 0;
}

int number_of_primes(int number_primes)
{
    int primes = 0;
    for (int i = 0; primes < number_primes; ++i)
    {
        if (is_prime(i))
        {
            primes++;
            printf("Prime number %d is : %d\n", primes, i);
        }
    }

    return primes;
}


int is_prime(int i)
{
    assert(i >= 0);

    if (i == 1)
    {
        return 0;
    }
    else if (i == 2)
    { 
        return 1;
    }
    else if (i % 2 == 0)
    {
        return 0;
    }
    else
    {
        int k, limit;
        limit = (int)(ceil(sqrt(i)));
        for (k = 3; k <= limit; k += 2)
        {
            if (i % k == 0)
            {
                return 0;
            }
        }
    return 1;
   }
}