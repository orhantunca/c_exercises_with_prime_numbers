#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int k,j;
    double i,counter;
    FILE *fptr;
    fptr=fopen("ilk 169 asal sayý.txt","w");
    float remainder;
    counter=0;
    i=2;
    while(counter<169)
   {
       k=0;                     
       for(j=2;j<i;j++)
       {
            remainder=fmod(i,j);      
            if(remainder==0)  
            {
                 k=1;
                 break;
            }
       }   
       if(k==0)
       {
       printf("%.0lf\n",i);
       fprintf(fptr,"%.0lf,",i);
       counter++;
       }
	   i++;   
   }
   return 0;
}
