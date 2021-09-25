#ifndef FUNCTIONS_H
#define FUNCTIONS_H
typedef int (*funcInt) (int*, int*); 
int add(int* x, int* y);
int substract(int* x, int* y);
int control(funcInt, int* x, int* y);
#endif