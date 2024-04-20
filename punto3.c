#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
  
   char *buff = (char *)malloc(100* sizeof(char)); 
   char  **nombres= (char **)malloc(5 *sizeof(char *)); 
   
   for (int i = 0; i < 5; i++)
   {
    
     printf("Ingrese el nombre:%d", i+1);
      gets(buff);

      nombres[i]= (char *)malloc((strlen(buff)+1)* sizeof(char));
      strcpy(nombres[i], buff);
      
   }
   
   for (int i = 0; i < 5; i++)
   {
      puts(nombres[i]);

   }

   free(buff);
   free(nombres);
   
  
}
