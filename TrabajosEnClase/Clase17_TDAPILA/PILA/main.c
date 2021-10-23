#include "main.h"

void probarIngresarYMostrarTexto(void) {
    char linea[90];
    int cant = 0;

    puts("Probando ingresar lineas de texto mostrandolas.\n"
         "=========      ============     ======     =====");

    while(ingresarTexto(linea, sizeof(linea)))
    {
        printf("\"%s\"\n", linea);
        cant++;
    }

    fprintf(stdout, "Se encontraron %d lineas de texto. \n\n", cant);

}

void probarIngresarYMostrarProducto(void) {
    tProd prod;
    int cant = 0;

    puts("Probando ingresar productos y mostrar productos.\n"
         "=========      ============     ======     =====");

    if(ingresarProducto(&prod))
        mostrarProducto(NULL);

    do {
        mostrarProducto(&prod);
        cant++;
    }while(ingresarProducto(&prod));

    fprintf(stdout, "Se encontraron %d productos\n\n", cant);

}

int main(){
    probarIngresarYMostrarProducto();
    probarIngresarYMostrarTexto();
    probarPonerYSacarPila();
    return 0;
}
