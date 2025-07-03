#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



#define ROJO "\033[1;31m"
#define VERDE "\033[1;32m"
#define AZUL "\033[1;34m"
#define MAX_ELEMENTOS 100
#define MAX_TEXTO 100

void MAYUS(char cadena[]) {
    int i;
    for (i = 0; cadena[i]; i++) {
        cadena[i] = toupper(cadena[i]);
    }
}

int libros = 0;


int main(int argc, char const *argv[])
{

    
    printf("indica la cantidad de libros a registrar: ");
    scanf("%d", &libros);


    system("cls");



    char titulos[MAX_ELEMENTOS][MAX_TEXTO], autores[MAX_ELEMENTOS][MAX_TEXTO], generos[MAX_ELEMENTOS][MAX_TEXTO];
    char ISBN[MAX_ELEMENTOS][MAX_TEXTO], BUSQUEDA[MAX_TEXTO];
    int stock [MAX_ELEMENTOS], i, j, encontrado = 0;
    float precio [MAX_ELEMENTOS], ganancias[MAX_ELEMENTOS];



    for (i = 0; i < libros; i++)
    {

        printf("libro numero %d\n", i + 1);
        printf("\n");
        printf("ingrese el titulo del libro:\n");
        scanf(" %[^\n]s", titulos[i]);
        MAYUS(titulos[i]);
        printf("ingrese el autor del libro:\n");
        scanf(" %[^\n]s", autores[i]);
        MAYUS(autores[i]);
        printf("ingrese el genero del libro:\n");
        scanf(" %[^\n]s", generos[i]);
        MAYUS(generos[i]);
        printf("ingrese el ISBN del libro:\n");
        scanf(" %[^\n]s", ISBN[i]);
            while (strlen(ISBN[i]) != 10) {
        printf("El ISBN debe tener exactamente 10 caracteres, intente de nuevo:\n");
        scanf(" %[^\n]s", ISBN[i]);
        MAYUS(ISBN[i]);
    }
        printf("ingrese el precio del libro:\n");
        scanf("%f", &precio[i]);
        while (precio[i] < 0) {
            printf("El precio no puede ser negativo, ingrese un precio valido:\n");
            scanf("%f", &precio[i]);
        }
        printf("ingrese el stock del libro:\n");
        scanf("%d", &stock[i]);
        ganancias[i] = precio[i] * stock[i];

        system("cls");
    }

    printf( AZUL "\n LIBROS:" "\033[0m\n");
    printf("\n");
    printf("%-20s|%-20s|%-20s|%-20s|%-20s|%-20s|%-20s\n", "TITULO", "AUTOR", "GENERO", "ISBN", "PRECIO", "STOCK", "GANANCIAS\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for( i = 0; i<libros; i++)
    {
printf("%-20s|%-20s|%-20s|%-20s|%-20.2f|%-20d|", 
        titulos[i], autores[i], generos[i], ISBN[i], precio[i], stock[i]);
    if (ganancias[i] >= 0)
        printf(VERDE "%-20.2f" "\033[0m", ganancias[i]);
    else
        printf(ROJO "%-20.2f" "\033[0m", ganancias[i]);
    printf("\n");
    }
    

    printf("\nIngrese el nombre, autor o ISBN del libro a buscar): ");
    scanf(" %[^\n]s", BUSQUEDA);
    MAYUS(BUSQUEDA);
    printf("RESULTADO DE LA BUSQUEDA:\n");

    for (i = 0; i < libros; i++) {
        if (
            strcmp(titulos[i], BUSQUEDA) == 0 ||
            strcmp(autores[i], BUSQUEDA) == 0 ||
            strcmp(ISBN[i], BUSQUEDA) == 0
        ) {
            printf("\t "AZUL" %s " "\033[0m\n", titulos[i]);
            printf("AUTOR: %s\n", autores[i]);
            printf("GENERO: %s\n", generos[i]);
            printf("ISBN: %s\n", ISBN[i]);
            printf("PRECIO: $%.2f\n", precio[i]);
            printf("STOCK: %d\n", stock[i]);
            if (ganancias[i] >= 0)
                printf("GANANCIA: " VERDE "%.2f" "\033[0m", ganancias[i]);
            else
                printf("GANANCIA: " ROJO "%.2f" "\033[0m", ganancias[i]);
            printf("\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontro ningun libro\n");
    }


    return 0;
}
