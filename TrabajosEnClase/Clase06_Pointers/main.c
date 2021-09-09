#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// ALWAYS INCLUDE THE FILE.H, FOR MAKE SURE THAT THE FILE.C WILL COMPILE ONLY ONCE TIME.
// In this case I have to include the file.c because in the file.h I don't include all
// the prototypes for the functions that I implement inside the file.c
// I don't know why VSCode doesn't allow me to include h files.
#include "String/stringCopy.c"

int main() {
    int *pointer;
    int data = 30;
    pointer = &data;
    *pointer = 55;
    printf("Data start with 30 and end with %d\n", data);
    // Data will be end with 55

    printf("Address of Data: %p\n", pointer);
    // With %p you can visualize the address of a variable in hexa.

    // Pointer Arithmetic
    // This depends in the base of each type of value.
    // 1 Byte  => bool, char
    // 4 Bytes => int,float
    // 8 Bytes => double
    pointer += 2;
    // This will be add 2 of the base size for this type of value.
    // Like 'pointer' is a pointer to an integer, it will increment the address by (4 * 2).
    // If 'pointer' was a pointer to a char, it will increment the address by (1 * 2).

    char origString[] = {"Hola como estas"}, destString[20], *aux; 
    time_t timeStringCopy = time(NULL);
    aux = stringCopy(destString, origString);
    timeStringCopy = time(NULL) - timeStringCopy;
    printf("Time: %ld seconds\n", timeStringCopy);

}
