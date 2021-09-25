#include <stdio.h>
#include "functions.h"

// 25-09-2021 We add a typedef for the function as parameter.

int add(int* x, int* y) {
    return (*x + *y); 
}

int subtract(int* x, int* y) {
    return (*x - *y);
}

int control(funcInt func, int* x, int* y) {
    return func(x,y);
}
