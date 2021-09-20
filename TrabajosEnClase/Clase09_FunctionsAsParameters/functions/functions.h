#ifndef FUNCTIONS_H
#define FUNCTIONS_H
int add(int* x, int* y);
int substract(int* x, int* y);
int control(int(*func)(int* x, int* y), int* x, int* y);
#endif