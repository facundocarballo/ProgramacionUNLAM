#include "arrays.h"
#include <stdio.h>

void createArray(Array *array) {
    array->cantElement = 0;
}

void printArray(Array *array) {
    if (array->cantElement == 0) {
        puts("This array is empty!");
        return;
    }
    for (int i = 0; i <= array->cantElement - 1; i++) {
        printf("array[%i] = [%d]\n", i, array->array[i]);
    }
    printf("--------------------------------------------------\n");
    return;

}

// TODO: fijarse si podemos reutilizar codigo aca..

int insertInArraySortFalling(Array *array, int element) {
    if (array->cantElement == Capacity) return ArrayIsFilled;
    int posAct = 0;
    // Get the position of the element in this array.
    while (posAct < array->cantElement && element < array->array[posAct]) 
    {
        // Like this sort is Falling, the most relevant element will be first. 
        // And the less relevant element will be the last.
        posAct++;
    }

    if (array->cantElement > 0 && element == array->array[posAct]) return Duplicate;

    // Expand the array and insert the element in the position that we get previously.
    int posIns = posAct;
    
    for (posAct = (array->cantElement - 1); (posAct >= posIns); posAct--)
    {
        array->array[posAct + 1] = array->array[posAct];
    }
    array->array[posIns] = element;
    array->cantElement++;
    return ArrayOK;
}

int insertInArraySortUpward(Array *array, int element) {
    if (array->cantElement == Capacity)
        return ArrayIsFilled;
    int posAct = 0;
    while(posAct < array->cantElement && element > array->array[posAct]) {
        posAct++;
    }
    if (array->cantElement > 0 && array->array[posAct] == element) return Duplicate;
    int posIns = posAct;
    for(posAct = array->cantElement - 1; posAct >= posIns; posAct--) {
        array->array[posAct + 1] = array->array[posAct];
    }
    array->array[posAct + 1] = element;
    array->cantElement++;
    return ArrayOK;
}


int insertInArrayAt(Array *array, int element, int pos) {
    if (array->cantElement == Capacity) return ArrayIsFilled;
    int posAct;
    for (posAct = array->cantElement - 1; posAct >= pos; posAct--) {
        array->array[posAct + 1] = array->array[posAct];
    }
    array->array[pos] = element;
    array->cantElement++;
    return ArrayOK;
}

int insertInArrayAtFirst(Array *array, int element) {
    if (array->cantElement == Capacity) return ArrayIsFilled;
    int posAct;
    for (posAct = array->cantElement - 1; posAct >= 0; posAct--) {
        array->array[posAct + 1] = array->array[posAct];
    }
    array->array[0] = element;
    array->cantElement++;
    return ArrayOK;
}

int insertInArrayAtEnd(Array *array, int element) {
    if (array->cantElement == Capacity) return ArrayIsFilled;
    array->array[Capacity - 1] = element;
    array->cantElement++;
    return ArrayOK;
}

bool deleteItemInArray(Array *array, int element) {
    // This function works with the array sort upward, falling and any disordered array.

    // If the element exists in the array, get the index of the element.
    int i = 0;
    while((i < array->cantElement) && (array->array[i] != element)) {
        i++;
    }
    if (i >= array->cantElement) return false;
    deleteItemInArrayAt(array, i);
    return true;
}

bool deleteItemInArrayAt(Array *array, int pos) {
    if (pos >= array->cantElement || pos < 0) return false;
    int aux = array->array[array->cantElement - 1];
    // We need an aux to save the elements that we can't delete.
    int aux2;
    // Set the last element of the list on NULL, the array is reduced by one.
    array->array[array->cantElement - 1] = NULL;

    for (int i = array->cantElement - 1; (pos < i); i--)
    {
        aux2 = array->array[i - 1];
        array->array[i - 1] = aux;
        aux = aux2;
    }
    array->cantElement--;
    return true;
}

bool deleteFirstItemInArray(Array *array) {
    return deleteItemInArrayAt(array, 0);
}

bool deleteLastItemInArray(Array *array) {
    return deleteItemInArrayAt(array, array->cantElement - 1);
}

bool searchItemInArray(Array *array, int element) {
    // This function works with the array sort upward, falling and any disordered array.

    // If the element are in the array, will return true.
    int i = 0;
    while((i < array->cantElement - 1) && (element != array->array[i])) {
        i++;
    }
    return (i < array->cantElement) ? false : true;
}

void sortArray(Array *array, bool upward) {
    // [1,2,4,5,7,9,10] Queremos esto
    // [4,7,10,2,5,1,9] Tenemos esto
    int aux;
    for (int i = 0; i < array->cantElement - 1; i++) {
        for (int h = 0; h < array->cantElement - 1; h++) {
            if ((upward) ? (array->array[h] > array->array[h + 1]) : (array->array[h] < array->array[h + 1]))
            {
                aux = array->array[h];
                array->array[h] = array->array[h + 1];
                array->array[h + 1] = aux;
            }
        }
    }
}
