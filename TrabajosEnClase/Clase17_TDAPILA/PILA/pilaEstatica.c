#include "main.h"

// PILA CON PRODUCTOS

int agregarProductoEnPila(tPila* p, tProd* prod)
{
    puts("Agregando productos en la pila....");
    mostrarProducto(NULL);
    int cant = 0;

    while(!pilaLlena(p, sizeof(*prod)) && ingresarProducto(prod))
    {
        if(!apilar(p,prod,sizeof(*prod)))
        {
            fprintf(stderr, "ERROR: Pila llena.");
            puts("No se pudo cargar el producto porque no hay lugar en la pila.");
        }
        mostrarProducto(prod);
        puts("----------    APILADO     ---------------");
        cant++;
    }
    printf("Se colocaron %d productos en la pila.\n", cant);

    return cant;
}

void probarVerTope(tPila* p, tProd* prod)
{
    if (verTope(p,prod, sizeof(*prod)))
    {
        mostrarProducto(NULL);
        mostrarProducto(prod);
    }else puts("La pila estaba vacia");
}

void probarTopePila(tPila* p, tProd* prod)
{
    if (verTope(p,prod,sizeof(*prod)))
    {
        puts("La pila no quedo vacia luego del desapilamiento.");
        mostrarProducto(NULL);
        mostrarProducto(prod);
    }else puts("La pila quedo vacia luego del desapilamiento");
}

void probarPilaVacia(tPila* p, tProd* prod, int* cant)
{
    puts("Probando pilaVacia() y desapilar().");
    if(pilaVacia(p))
        puts("La pila esta vacia.");
    else {
        mostrarProducto(NULL);
        while(desapilar(p,prod,sizeof(*prod)))
        {
            mostrarProducto(prod);
            *cant--;
        }
    }

    probarTopePila(p, prod);

}

void probarVaciarPila(tPila* p)
{
    vaciarPila(p);
    if (pilaVacia(p))
        puts("La pila se vacio por completo!");
    else
        fprintf(stderr, "ERROR: la pila deberia estar vacia, pero no lo esta.");

}

void probarPilaConProductos()
{
    printf("-----------    PROBANDO PILA CON PRODUCTOS   -------------\n");
    tPila pila;
    tProd prod;
    crearPila(&pila);

    int cant = agregarProductoEnPila(&pila,&prod);
    probarPilaVacia(&pila, &prod, &cant);
    probarVerTope(&pila,&prod);
    probarVaciarPila(&pila);
}

// PILA CON TEXTO
void probarPilaLlenaYApilar(tPila* p, tProd* prod, char* linea)
{
    puts("Apilando texo");
    int cant = 0;

    while(!pilaLlena(p, sizeof(prod)) && ingresarTexto(linea, sizeof(linea)))
    {
        if (!apilar(p,linea,strlen(linea) + 1))
        {
            fprintf(stderr, "ERROR: no se pudo agregar texto a la pila, pila llena.");
            puts("No se pudo cargar el texto a la pila, porque estaba llena.");
        }else {
            printf("\"%s\"\n", linea);
            cant++;
        }
    }
     printf("Se apilaron %d lineas de texto en la pila.\n", cant);
}

void quitarLineasPila(tPila *p, char* linea)
{
    puts("Quitar lineas de la pila");
    int cant = 0;
    while(desapilar(p,linea,sizeof(linea)))
    {
        cant++;
        printf("\"%s\"\n", linea);
    }
    printf("Se sacaron y mostraron %d lineas de la pila.\n", cant);
}


void probarPilaConTexto()
{
    puts("----------    PROBANDO PILA CON TEXO  --------------");
    tPila pila;
    tProd prod;
    char linea[70];

    probarPilaLlenaYApilar(&pila, &prod, &linea);
    quitarLineasPila(&pila, &linea);

}

void probarPonerYSacarPila()
{
    probarPilaConProductos();
    probarPilaConTexto();

}
