#include<stdio.h>
#include<stdlib.h>
#include<math.h>


unsigned long long b[1000]={0};
unsigned long long c[1000]={0};

int divisor(unsigned long long serie,unsigned long long prime);
void find_prime_factors(unsigned long long serie);
void print_prime_factors(void);
unsigned long long next_prime(unsigned long long prime);
unsigned long long power(unsigned long long number1,unsigned long long number2);

int main()
{
	unsigned long long serie;
	int n,i;
	
	
	for(n=1;n<=11;n++)
	{
		serie=7+power(30,n);
		find_prime_factors(serie);
		print_prime_factors();
		for(i=0;i<1000;i++)
		{
			b[i]=0;
            c[i]=0;
		}
	}
    
	
    printf("\n");
    return 0;
}
int divisor(unsigned long long serie,unsigned long long prime)
{
	if(serie%prime==0)
		return 1;
	else if(prime>sqrt(serie))
	    return 2;
	else
		return 0;
}
void find_prime_factors(unsigned long long serie)
{
	int i,prime,a;
	
	printf("%20llu",serie);
	
	prime=3;
	i=0;
	
	while(serie!=1)
	{
		a=divisor(serie,prime);
		
		if(a==1)
		{
			serie=serie/prime;
			if(b[i]==prime)
			{
			    c[i]++;
			}
			else
			{   
				if(b[i]!=0)
					i++;
				b[i]=prime; 
				c[i]++;
		    }
		}
		else if(a==2)
		{   i++;
			b[i]=serie;
			serie=1;
			c[i]++;
		}
		else
	    {
	    	prime=next_prime(prime);
		}
    }
}
void print_prime_factors(void)
{
	unsigned long long i,j;
	
	printf("\t");
	for(i=0;i<1000;i++)	
	{
		if(b[i]!=0)
		{   
			if(c[i]==1)	
				printf("%llu*",b[i]);
			else
				printf("%lluuzeri%llu*",b[i],c[i]);
		}
	}
	printf("\n");	
}
unsigned long long next_prime(unsigned long long prime)
{
	   unsigned long long k,j;
	   float remainder;
	   do
	   {
	   
	   		prime=prime+2;
	   		k=0;                     
       		for(j=3;j<sqrt(prime);j=j+2)
       		{
            	remainder=fmod(prime,j);      
            	if(remainder==0)  
            	{
                	 k=1;
                 	 break;
            	}
       		}   
       		if(k==0)
       		{
       		 	return prime;
       		}
       }while(k!=0);
   
}

unsigned long long power(unsigned long long number1,unsigned long long number2)
{
	unsigned long long result,i;
	
	result=1;
	
	for(i=1;i<=number2;i++)
	{
		result=result*number1;
	}
	
	return result;
}
