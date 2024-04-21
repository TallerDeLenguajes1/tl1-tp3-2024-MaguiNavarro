#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

 struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos  ;       // El tamaño de este arreglo depende de la variable // "CantidadProductosAPedir"
}typedef Cliente;

float costoTotal(Producto productos){

    float total;
    total= productos.Cantidad * productos.PrecioUnitario;

    return total;
}
int main(){
   srand(time(NULL));
    Cliente *clientes;
    int cantClientes;

    printf("Ingrese la cantidad de clientes:\n");
    scanf("%d", &cantClientes); 
     fflush(stdin);
    clientes= (Cliente *)malloc(cantClientes * sizeof(Cliente));
    char *buff= (char*)malloc(100* sizeof(char));
   
   puts("*****CARGAR LOS CLIENTES*****");
   for (int i = 0; i < cantClientes; i++)
   {
      printf("\nCliente numero:%d", i+1);
      clientes[i].ClienteID= i;

      printf("\nNombre del Cliente:");
      gets(buff);
      clientes[i].NombreCliente= malloc((strlen(buff) +1)* sizeof(char));
      strcpy(clientes[i].NombreCliente, buff);

      printf("Productos a pedir: \n");
      clientes[i].CantidadProductosAPedir= 1 + rand()% 5;

      
      clientes[i].Productos= malloc(clientes[i].CantidadProductosAPedir*sizeof(int));

      for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
      {
         printf("Producto numero:%d", j+1);
         clientes[i].Productos[j].ProductoID = j;
         puts("\nCantidad: ");

         clientes[i].Productos[j].Cantidad= 1 + rand()% 10;
         clientes[i].Productos[j].TipoProducto = TiposProductos[rand()% 5];
         clientes[i].Productos[j].PrecioUnitario= (100 + rand()% 901)/10;

      }
      
   }

   printf("***COSTO TOTAL***");

for (int i = 0; i <= cantClientes; i++)
{
    float total = 0;
        printf("Cliente numero: %d\n", clientes[i].ClienteID + 1 );
        printf("Nombre del cliente: ");
        puts(clientes[i].NombreCliente);
        printf("Productos pedidos: %d\n", clientes[i].CantidadProductosAPedir);

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
             puts("------------------");
            printf("Producto numero: %d\n", clientes[i].Productos[j].ProductoID +1);
            printf("Tipo del producto: ");
            puts(clientes[i].Productos[j].TipoProducto);
            printf("Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Precio unitario: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("Costo total: %.2f\n", costoTotal(clientes[i].Productos[j]));
            puts("*********");
            total += costoTotal(clientes[i].Productos[j]);
        }
        printf("\nTotal a pagar por el cliente %d es  : %.2f", clientes[i].ClienteID + 1, total);

}


    free(clientes);
    free(buff);

}