#include <stdio.h>
#include "./functions/functions.c"
/*
I have to include always files.c instead of files.h beacuse VSCode doesn't have support for projects in C or C++.
I work like individual files, not like a project. If this were a project, when I built it the compiler will compile
all the files.c that the project had, but in this case I have to tell the compiler what files I will need.
*/


int main() {
    int x, y;
    puts("Welcome, you will have to give us two numbers");
    printf("Please enter the first number: ");
    scanf("%d", &x);
    fflush(stdin);
    printf("Please enter the second number: ");
    scanf("%d", &y);
    fflush(stdin);
    int addRes = add(&x,&y);
    int subRes = subtract(&x, &y);
    int controlRes = control(add, &x, &y);
    printf("Add Result: %d\n", addRes);
    printf("Substract Result: %d\n", subRes);
    printf("Control Result: %d\n", controlRes);
    return 0;
}