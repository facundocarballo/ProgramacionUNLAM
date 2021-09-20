#include <stdio.h>
#include "functions.h"

int add(int* x, int* y) {
    return (*x + *y); 
}

int subtract(int* x, int* y) {
    return (*x - *y);
}

int control(int(*func)(int* x, int* y), int* x, int* y) {
    return ((*func)(x,y));
}
