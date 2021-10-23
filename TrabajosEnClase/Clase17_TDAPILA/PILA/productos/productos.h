#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#include "stdio.h"
#include "../defs.h"

typedef struct { char codProd[11], descrip[46]; } tProd;

bool ingresarProducto(tProd* d);

void mostrarProducto(const tProd* d);

#endif // PRODUCTOS_H_
