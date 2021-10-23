#ifndef PILA_H_
#define PILA_H_

#include "defs.h"

// Implementacion Estatica

#define TAM_PILA 340

// PILA ESTATICA
typedef struct
{
    char pila[TAM_PILA];
    unsigned tope;
} tPila;

void crearPila(tPila* p);
void vaciarPila(tPila* p);
bool apilar(tPila *p, const void* d, unsigned cantBytes);
bool desapilar(tPila *p, const void* d, unsigned cantBytes);
bool pilaLlena(const tPila *p, unsigned cantBytes);
bool pilaVacia(const tPila* p);
bool verTope(const tPila* p, void* d, unsigned cantBytes);

// PILA DINAMICA
typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}tNodo;
typedef tNodo* tPilaDinamica;

void crearPilaDIN(tPilaDinamica* p);
bool pilaLlenaDIN(tPilaDinamica* p, unsigned cantBytes);
bool apilarDIN(tPilaDinamica* p, const void* d, unsigned cantBytes);
bool verTopeDIN(const tPilaDinamica* p, void* d, unsigned cantBytes);
bool pilaVaciaDIN(const tPilaDinamica* p);
void vaciarPilaDIN(tPilaDinamica* p);
bool desapilarDIN(tPilaDinamica* p, void* d, unsigned cantBytes);


#endif // PILA_H_
