#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANIO 5
#define MESES 12

void promedio(int matriz[ANIO][MESES]);
void valoresMaximo(int matriz[ANIO][MESES]);
void valoresMinimo(int matriz[ANIO][MESES]);

int main(){

    srand(time(NULL));

    int mt[ANIO][MESES];
    float prom;
    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            mt[i][j]= 10000 + rand()% (50000 - 10000 + 1);
        
        }
      
    }
    
    for (int i = 0; i < ANIO; i++)
    {
        for (int j = 0; j< MESES; j++)
        {
           printf("%d ", mt[i][j]);   
        }
        printf("\t \n");
    }
    
     promedio(mt);
     valoresMaximo(mt);
     valoresMinimo(mt);
  
   return 0; 

}

void promedio(int matriz[ANIO][MESES]){

    for (int i = 0; i < ANIO; i++)
    {
        float promedio=0;

        for (int j=0 ; j < MESES; j++)
        {
          promedio += matriz[i][j];
        }
       promedio= promedio/MESES; 
       printf("EL Promedio es: %f", promedio);
    }
     
}

void valoresMaximo(int matriz[ANIO][MESES]){
      int max= matriz[0][0];
      int mes, anio;
      int i,j;

      for ( i = 1; i < ANIO; i++)
      {
        for ( j= 1; j < MESES; j++)
        {
            if (max < matriz[i][j])
            {
                max= matriz[i][j];
                mes= j+1;
                anio= i+1;
            }
 
        }
        
      }
      printf("\nEl valor maximo es: %d en el mes:%d, Anio: %d", max,mes,anio);

}
void valoresMinimo(int matriz[ANIO][MESES]){
      int min= matriz[0][0];
      int mes, anio;
      int i,j;

      for ( i = 0; i < ANIO; i++)
      {
        for ( j= 0; j < MESES; j++)
        {
            if (min > matriz[i][j])
            {
                min= matriz[i][j];
                mes= j + 1;
                anio= i+1;
            }
 
        }
        
      }
      printf("\nEl valor minimo es: %d en el mes:%d, Anio: %d", min,mes,anio);
}