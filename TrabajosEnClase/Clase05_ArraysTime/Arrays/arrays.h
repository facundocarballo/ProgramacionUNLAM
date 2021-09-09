#ifndef ARRAYS_H
#define ARRAYS_H

#define Capacity        100000
#define ArrayIsFilled   0
#define ArrayOK         1
#define Duplicate       2

#include "../../Comun/bool.h"

typedef struct
{
    int array[Capacity];
    int cantElement;
} Array;

void createArray(Array *array);
void printArray(Array *array);

int insertInArraySortUpward(Array *array, int element);
int insertInArraySortFalling(Array *array, int element);
int insertInArrayAt(Array *array, int element, int pos);
int insertInArrayAtFirst(Array *array, int element);
int insertInArrayAtEnd(Array *array, int element);


// bool deleteItemInArraySortUpward(Array *array, int element);
// bool deleteItemInArraySortFalling(Array *array, int element);
// bool deleteItemInArrayDisordered(Array *array, int element);
bool deleteItemInArray(Array *array, int element);
bool deleteItemInArrayAt(Array *array, int pos);
bool deleteFirstItemInArray(Array *array);
bool deleteLastItemInArray(Array *array);


// bool searchItemInArraySortUpward(Array *array, int element);
// bool searchItemInArraySortFalling(Array *array, int element);
// bool searchItemInArrayDisordered(Array *array, int element);
bool searchItemInArray(Array *array, int element);

void sortArray(Array *array, bool upward);
void sortArraySelection(Array *array, bool upward);
void sortArrayInsertion(Array *array, bool upward);
// void sortArrayUpward(Array *array);
// void sortArrayFalling(Array *array);

#endif