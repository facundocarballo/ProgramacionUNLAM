#include "lineasDeTexto.h"

bool ingresarTexto(char* linea, int tamLinea) {
    static const char* texto[] = {
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, gna aliqua.",
        "",
        "Habitant morbi tristique senectus et netus et malesuada.",
        "A condimentum vitae sapien pellentesque habitant morbi tristique senectus.",
        "Viverra vitae congue eu consequat ac felis.",
        "",
        "Hola mundoooo!",
        NULL,
    };
    static int posi = 0; // El static obliga a que esta variable solo se declare una sola vez.

    if (texto[posi] == NULL) {
        posi = 0;
        return false;
    }

    *linea = '\0';
    strncat(linea, texto[posi], tamLinea - 1);
    posi++;

    return true;
}
