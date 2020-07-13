#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int
    filas = 15;

    

int main()
{
    srand(time(NULL));
    int i, j, elementosAleatorios = 0, acumulador = 0;
    int columnas = rand() % 11 + 5; //  numero aleatorio entre 5 y 15
    int *ptrMatriz, *pares;
    
    //reserva de memoria dinamica
    ptrMatriz =(int *)malloc(filas * columnas * sizeof (int));
    pares = (int *)malloc(filas * sizeof(int));

    //cargo los elementos 
    for(i = 0; i < filas * columnas; i++)
    {
        elementosAleatorios = rand() % 900 + 100;
        *(ptrMatriz + i) = elementosAleatorios; 
    }

    //muestro por pantalla la matriz con su respectiva dimension
    printf("\nMatriz = [ %d ] [%d]\n", filas, columnas);                    

    //imprimiendo los elementos del arreglo con el puntero
    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            printf("%d  ", *(ptrMatriz + (i * columnas + j)));
        }
        printf("\n");
    }

    //numeros pares por filas
    printf("\nNumeros pares segun la fila \n");
    for(i = 0; i< filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            if( *(ptrMatriz + (i * columnas + j)) % 2 == 0)
            acumulador++;
        }
        printf(" Fila %d = %d\n",i+1,acumulador);
        *(pares+i) = acumulador; //guardo el valor de cada elemento par de cada fila
        acumulador = 0;
        
    }
 
    //vector dinamico de 15 elementos
    printf("\nVector dinamico:\n");
    for(i = 0; i< filas; i++)
    {  
        printf("%4d",*(pares + i)); //4d% 4 espacios visuales entre cada elemento
    }

  
    getchar();
    return 0;
}


