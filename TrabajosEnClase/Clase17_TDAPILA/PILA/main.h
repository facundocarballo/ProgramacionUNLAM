#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "stdio.h"
#include "productos/productos.h"
#include "lineasDeTexto/lineasDeTexto.h"
#include "pila.h"

void probarIngresarYMostrarProducto(void);
void probarIngresarYMostrarTexto(void);
void probarPonerYSacarPila(void);

// PILA ESTATICA
int agregarProductoEnPila(tPila* p, tProd* prod);
void probarVerTope(tPila* p, tProd* prod);
void probarTopePila(tPila* p, tProd* prod);
void probarPilaVacia(tPila* p, tProd* prod, int* cant);
void probarVaciarPila(tPila* p);
void probarPilaConProductos();
void probarPilaLlenaYApilar(tPila* p, tProd* prod, char* linea);
void quitarLineasPila(tPila *p, char* linea);
void probarPilaConTexto();
void probarPonerYSacarPila();

//PILA DINAMICA
void probarPilaDinamica(void);




#endif // MAIN_H_INCLUDED
