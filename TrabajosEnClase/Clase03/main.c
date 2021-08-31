#include <stdio.h>
#include <stdlib.h>
#include "Arrays/arrays.c"

int main() {
    Array fallingArray;
    createArray(&fallingArray);
    puts("Falling array");
    insertInArraySortFalling(&fallingArray, 1);
    insertInArraySortFalling(&fallingArray, 3);
    insertInArraySortFalling(&fallingArray, 5);
    insertInArraySortFalling(&fallingArray, 7);
    insertInArraySortFalling(&fallingArray, 9);
    insertInArraySortFalling(&fallingArray, 10);
    printArray(&fallingArray);

    Array upwardArray;
    createArray(&upwardArray);
    puts("Upward array");
    insertInArraySortUpward(&upwardArray, 10);
    insertInArraySortUpward(&upwardArray, 9);
    insertInArraySortUpward(&upwardArray, 7);
    insertInArraySortUpward(&upwardArray, 5);
    insertInArraySortUpward(&upwardArray, 4);
    insertInArraySortUpward(&upwardArray, 2);
    insertInArraySortUpward(&upwardArray, 1);
    printArray(&upwardArray);

    puts("Insert In Array At...");
    insertInArrayAt(&upwardArray, 77, 4);
    printArray(&upwardArray);

    puts("Insert In Array At First");
    insertInArrayAtFirst(&upwardArray, 100);
    printArray(&upwardArray);

    puts("Insert In Array At End");
    insertInArrayAtEnd(&upwardArray, 1000);
    printArray(&upwardArray);

    puts("Delete Item In Array");
    puts("Upward:");
    deleteItemInArray(&upwardArray, 1000);
    printArray(&upwardArray);

    puts("Falling");
    deleteItemInArray(&fallingArray, 3);
    printArray(&fallingArray);

    puts("Delte Item In Array At: 1");
    deleteItemInArrayAt(&fallingArray, 1);
    printArray(&fallingArray);

    puts("Sort Array Upward");
    sortArray(&fallingArray, true);
    printArray(&fallingArray);

    puts("Array Before:");
    printArray(&upwardArray);
    puts("Sort Array Falling");
    sortArray(&upwardArray, false);
    printArray(&upwardArray);
}