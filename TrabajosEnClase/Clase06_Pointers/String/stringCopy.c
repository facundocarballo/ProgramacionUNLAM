#include "stringCopy.h"

char *stringCopy(char *dest, char *orig) {
    char *aux = dest;
    // 'aux' contains the address of the first char of the 'dest' string.
    while(*orig) {
        // While the char that point 'orig' be different to '/0', execute this code.
        *dest = *orig;
        // The char that pointing 'orig' put in the address that 'dest' is pointing to.
        orig++;
        dest++;
        // Increment the address of this pointers, so in the next loop will be pointing to the next char.
    }
    // If 'orig' is pointing to '/0', will leave the while
    *dest = '\0';
    // And we have to add manually the '/0'.
    return aux;
}