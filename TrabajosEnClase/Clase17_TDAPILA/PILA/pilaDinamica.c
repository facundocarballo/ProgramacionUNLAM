#include "main.h"

// PILA CON PRODUCTOS

void apilarYPilaLlena(tPilaDinamica* p, tProd* prod, int* cant)
{
    mostrarProducto(NULL);
    while(!pilaLlenaDIN(p, sizeof(*prod)) && ingresarProducto(prod))
    {
        if (!apilarDIN(p, prod, sizeof(*prod)))
        {
            fprintf(stderr, "ERROR: No se pudo apilar, pila llena.");
            printf("ERROR: no se pudo apilar, pila llena\n");
        }
        mostrarProducto(prod);
        *cant++;
    }
    printf("Se apilaron %d productos en la pila.\n", *cant);
}

void probandoVerTopeDIN(const tPilaDinamica* p, const tProd* otro)
{
    puts("Probando ver tope de la pila.");

    if (verTopeDIN(p,otro, sizeof(*otro)))
    {
        mostrarProducto(NULL);
        mostrarProducto(otro);
    }else puts("La pila estaba vacia.");
}

void pilaVaciaYDesapilar(tPilaDinamica* p, tProd* prod, int* cant)
{
    puts("Probando pila vacia y despilar.");

    if (pilaVaciaDIN(p))
        puts("La pila estaba vacia.");
    else
        mostrarProducto(NULL);

    while((*cant > 0) && desapilarDIN(p,prod,sizeof(*prod)))
    {
        mostrarProducto(prod);
        *cant--;
    }
}

void vaciarPilaPilaVacia(tPilaDinamica* p)
{
    puts("Probando vaciarPila y pilaVacia.");

    vaciarPilaDIN(p);
    if (pilaVaciaDIN(p))
        puts("La pila esta vacia!");
    else
        puts("vaciarPila no funciona, la pila tiene informacion.");

}

// PILA CON TEXTO

void probandoPilaLlenaYApilar(tPilaDinamica* p, char* linea, tProd* prod, int* cant)
{
    while(!pilaLlenaDIN(p, sizeof(*prod)) && ingresarTexto(linea, sizeof(linea)))
    {
        if (!apilarDIN(p,linea,strlen(linea) + 1))
        {
            fprintf(stderr, "ERROR: No se pudo apilar, pila llena.");
            printf("ERROR: no se pudo apilar, pila llena\n");
        }
        printf("\"%s\"\n", linea);
        *cant++;
    }
    printf("Se apilaron %d lineas de texto.\n", *cant);
}

void probandoDesapilar(tPilaDinamica* p, char* linea, int* cant)
{
    *cant = 0;
    while(desapilarDIN(p,linea,sizeof(linea)))
    {
        *cant++;
        printf("\"%s\"\n", linea);
    }
    printf("Se desapilaron y se mostraron %d lineas de texto de la pila.", *cant);
}



void probarPonerYSacarPilaDIN(void)
{
    tProd producto, otro;
    tPilaDinamica pila;
    char linea[70];
    int cant = 0;

    puts("--------      PROBANDO PILA DINAMICA CON PRODUCTOS        -------------");
    puts("========================================================================");

    apilarYPilaLlena(&pila, &producto, &cant);
    probandoVerTopeDIN(&pila, &otro);
    pilaVaciaYDesapilar(&pila, &producto, &cant);
    vaciarPilaPilaVacia(&pila);

    puts("-------       PROBANDO PILA DINAMICA CON LINEAS DE TEXTO  -------------");
    puts("=======================================================================");

    probandoPilaLlenaYApilar(&pila, &linea, &producto, &cant);
    probandoDesapilar(&pila, &linea, &cant);

}
