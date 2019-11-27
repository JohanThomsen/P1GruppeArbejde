    #include <stdio.h>
    #include <ctype.h>

    int main()
      
    {
      
        int a, b;
	
	char c;
	
        
        printf("Indsaet to positive heltal: ");
	
	
        scanf("%d %d",&a,&b);  /* Her indlæses input i form af to tal */
	
	scanf("%c", &c);
	

if (isalpha(c)!= 0)
  
        {
	  
             printf("%c er et bogstav, indtast to positive heltal\n", c);

       	}
 
else {
	
          while(a!=b)
	  
          {
	    
              if(a > b)
    	      a -= b; /* Altså vil man her finde differensen og tildele denne værdi til a, dette er det samme som "a = a - b" */

              else
              b -= a;
	      
          }
	  
	
        printf("Stoerste faelles divisor = %d\n",a); /* Her printes den største fælles divisor for de to tal */
	
     }
	
        return 0;
	
    }
