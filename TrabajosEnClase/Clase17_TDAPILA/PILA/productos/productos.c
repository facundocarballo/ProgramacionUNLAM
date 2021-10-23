#include "productos.h"

bool ingresarProducto(tProd* d) {
    static const tProd productos[] = {
        { "clavo33", "El mejor clavo" },
        { "martillo21", "El mejor martillo" },
        { "tornillo21", "El mejor tornillo" },
        { "trapo21", "El mejor trapo" },
        { "juguete31", "El mejor juguete" },
        { "manaos31", "El mejor manaos" },
        { "hilo21", "El mejor hilo" },
        { "oro21", "El mejor oro" },
        { "lenceria31", "El mejor lenceria" },
        { "auto21", "El mejor auto" }
    };
    static int posi = 0;

    if (posi == ( sizeof(productos) / sizeof(tProd) ) ) {
        posi = 0;
        return false;
    }

    *d = productos[posi];
    posi++;

    return true;

}

void mostrarProducto(const tProd* d) {
    if (d) // Si el puntero "d" apunta hacia un lugar distinto de NULL, entrara
        fprintf(stdout, "%-*s       %-*s ... \n", sizeof(d->codProd) - 1, d->codProd, sizeof(d->descrip) - 1, d->descrip);
    else
        fprintf(stdout, "%-*.*s     %-*.*s ...\n", sizeof(d->codProd) - 1, sizeof(d->codProd) - 1, "Cod. Producto",
                sizeof(d->descrip) + 1, sizeof(d->descrip) + 1, "Descripcion del producto");

}
