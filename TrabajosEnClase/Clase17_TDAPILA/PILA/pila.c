#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

// PILA ESTATICA
void vaciarPila(tPila* p)
{
    p->tope = TAM_PILA;
}

void crearPila(tPila* p)
{
    p->tope = TAM_PILA;
}

bool pilaLlena(const tPila *p, unsigned cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned);
}

bool pilaVacia(const tPila* p)
{
    return p->tope == TAM_PILA;
}

bool apilar(tPila *p, const void* d, unsigned cantBytes)
{
    if (p->tope < cantBytes + sizeof(unsigned)) return false;

    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);
    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));

    return true;
}

bool desapilar(tPila* p, const void* d, unsigned cantBytes)
{
    if (pilaVacia(p)) return false;

    unsigned tamInfo;

    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);
    memcpy(d, p->pila + p->tope, min(cantBytes, tamInfo));
    p->tope += tamInfo;


    return true;
}

bool verTope(const tPila* p, void* d, unsigned cantBytes)
{
    unsigned tamInfo;

    if (p->tope == TAM_PILA) return false;

    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), min(cantBytes, tamInfo));

    return true;
}

// PILA DINAMICA
void crearPilaDIN(tPilaDinamica* p)
{
    *p = NULL;
}

bool pilaLlenaDIN(tPilaDinamica* p, unsigned cantBytes)
{
    //  NOTA: No la entiendo muy bien la funcion.
    //  Entiendo que malloc reserva espacio en memoria, pero no entiendo porque se libera (free())
    //  y porque luego se comparan.

    tPilaDinamica* aux = (tPilaDinamica *)malloc(sizeof(tPilaDinamica));
    void* info = malloc(sizeof(cantBytes));

    free(aux);
    free(info);

    return (aux == info) || (info == NULL);
}

bool apilarDIN(tPilaDinamica* p, const void* d, unsigned cantBytes)
{
    tNodo* nue; // Creamos un putero tipo PILA

    if ((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes) == NULL) )
    {
        // No se pudo apilar, pila llena.
        // Ya sea por no hay espacio en la computadora para crear una estructura nueva de pila dinamica (primer condicion)
        // o porque no hay suficiente espacio para asignar en el puntero "info" la cantidad de bytes que se solicitan.
        free(nue);
        return false;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;

    return true;

}

bool verTopeDIN(const tPilaDinamica* p, void* d, unsigned cantBytes)
{
    if (*p == NULL) return false; // Pila vacia

    memcpy(d, (*p)->info, min(cantBytes, (*p)->tamInfo));
    return true;
}

bool pilaVaciaDIN(const tPilaDinamica* p)
{
    return *p == NULL;
}

void vaciarPilaDIN(tPilaDinamica* p)
{
    while(*p)
    {
        tNodo* aux = *p;    // aux se queda con lo que apunta p
        *p = aux->sig;              // p ahora se queda con lo que apuntaba p->sig
        free(aux->info);
        free(aux);                  // liberamos de memoria la informacion y la estructura.
    }
}

bool desapilarDIN(tPilaDinamica* p, void* d, unsigned cantBytes)
{
    tNodo* aux = *p;        // aux se queda con el puntero de p.

    if (aux == NULL) return false;  // No hay nada que desapilar, porque la pila esta vacia.
    *p = aux->sig;                  // p se queda con el puntero siguiente.
    memcpy(d, aux->info, min(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);
    // Liberamos espacio de memoria segun la informacion que desapilamos, y la estructura tPilaDinamica.

    return true;
}



