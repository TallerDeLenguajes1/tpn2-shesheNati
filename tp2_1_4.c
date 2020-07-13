#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char tipos[6][10] = {"Intel","AMD", "Celeron", "Athlon", "Core", "Pentium"}; // declaro de manera global para poder usarlo en fuera del main

/**********DECLARACION*************/
typedef struct
{
    int velocidad; //entre 1 y 3 Gherz
    int anio; //entre 2000 y 2017
    int cantidad_nucleos; //entre 1 y 4
    char *tipo_cpu; //valores del arreglo tipos
}compu;


/*******  prototipos        ********/
void cargarCaracteristicas(compu *pc);
void cargarPC(compu *arregloDePC, int cantidad);
void mostrarListaDePC(compu *arregloDePC, int cantidad);
void mostrarPCAntigua(compu *arregloDePC, int cantidad);
void mostrarMasVeloz(compu *arregloDePC, int cantidad);

/****** programa principal******/
int main()
{
    compu *computadoras;
    int cantCompu;

    srand(time(NULL));

    printf("Cantidad de PC que quiera ingresar:");
    scanf("%d", &cantCompu);

    computadoras = (compu*)malloc(cantCompu * sizeof(compu));//arreglo dinamico

    cargarPC(computadoras, cantCompu);
    mostrarListaDePC(computadoras, cantCompu);
    mostrarPCAntigua(computadoras, cantCompu);
    mostrarMasVeloz(computadoras, cantCompu);

    scanf(" %c");
    free(computadoras);
    
    return 0;
}

//FUNCIONES

void cargarCaracteristicas(compu *pc)
{
    pc->velocidad = rand() % 4 + 1;
    pc->anio = rand() % 18 + 2000;
    pc->cantidad_nucleos = rand() % 5 + 1;
    pc->tipo_cpu = (char *) malloc(sizeof(char) * 10); //reservo memoria para el arreglo de cadena de caracteres
    strcpy(pc->tipo_cpu, tipos[rand() % 6 + 0]);
}



void cargarPC(compu *arregloDePC, int cantidad)
{
    for(int i = 0; i < cantidad; i++)
    {
        cargarCaracteristicas(arregloDePC + i);
    }
}



void mostrarListaDePC(compu *arregloDePC, int cantidad) //parametros puntero al arreglo del tipo de la estructura y la cant de compus
{
    printf("\n Lista de las PCs y sus caracteristicas:\n");
    for(int i = 0; i < cantidad; i++ )
    {
        printf("\n %d)", i + 1);
        printf("Velocidad de procesamiento(GHz): %d\n", (arregloDePC +i)->velocidad);
        printf("Año de fabricacion: %d\n", (arregloDePC + i)->anio);
        printf("Cantidad de nucleos: %d\n",(arregloDePC +i)->cantidad_nucleos);
        printf("Tipo de procesador: %s\n", (arregloDePC + i)->tipo_cpu);
    }
    printf(" \n");
}


void mostrarPCAntigua(compu *arregloDePC, int cantidad)
{
    compu aux = *arregloDePC; // considero la primera pc como la mas antigua

    for(int i = 0; i < cantidad; i++)
    {
        if((arregloDePC + i)->anio < aux.anio) //uso notacion de punteros 
       {
           aux = *(arregloDePC + i);
       }
    }

    printf(" PC mas antigua: %d\n", aux.anio);
}


void mostrarMasVeloz(compu *arregloDePC, int cantidad)
{
    compu aux = *arregloDePC; // considero la primera pc como la mas lenta

    for(int i = 0; i < cantidad; i++)
    {
        if((arregloDePC + i)->velocidad > aux.velocidad) //uso notacion de punteros 
       {
           aux = *(arregloDePC + i);
       }
    }

    printf(" PC mas Veloz: %d Ghz del tipo %s \n", aux.velocidad, aux.tipo_cpu);
}