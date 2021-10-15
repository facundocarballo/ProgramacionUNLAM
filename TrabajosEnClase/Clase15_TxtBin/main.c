#include <stdio.h>
#include "./handlers.c"

/*
To make a generic function who converts binary files to text files and vice versa,
it's needed know the format of these files. Because of that, I will use two test
files that I will create with two functions, these functions will be in the
handlers.c file.
*/
/*
Para poder realizar una funcion generica que convierta un archivo de texto a un archivo binario y viceversa, es
necesario que sepa el formato del archivo con el que voy a trabajar para poder transformarlo.
Por esto, voy a usar dos archivos de prueba uno binario y otro de texto con los que voy a trabajar.
Estos mismos archivos se encuentran dentro de la carpeta Clase15_TxtBin.
*/

int main() {
    char res = TxtTOBin("fileTXT", "newBIN");
    if(res) 
        printf("TXTtoBIN sucessfully!\n");
    res = BinToTxt("fileBIN", "newTXT");
    if (res)
        printf("BinToTxt sucessfully!\n");

    return 0;
}