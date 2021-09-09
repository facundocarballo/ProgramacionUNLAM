#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// ALWAYS INCLUDE THE FILE.H, FOR MAKE SURE THAT THE FILE.C WILL COMPILE ONLY ONCE TIME.
// In this case I have to include the file.c because in the file.h I don't include all
// the prototypes for the functions that I implement inside the file.c
#include "Arrays/arrays.c"

int main() {
    srand(time(NULL));
    Array arrayInsertion;
    createArray(&arrayInsertion);
    for (int i = 0; i < 100000; i++) {
        insertInArrayAt(&arrayInsertion, rand(), i);
    }
    Array arraySelection = arrayInsertion;
    Array arraySort = arraySelection;
    time_t timeInsertion = time(NULL);
    sortArrayInsertion(&arrayInsertion, true);
    timeInsertion = time(NULL) - timeInsertion;
    time_t timeSelection = time(NULL);
    sortArraySelection(&arraySelection, true);
    timeSelection = time(NULL) - timeSelection;
    time_t timeSort = time(NULL);
    sortArray(&arraySort, true);
    timeSort = time(NULL) - timeSort;
    printf("The function 'sortArrayInsertion' was executed in %ld seconds\n", timeInsertion);
    printf("The function 'sortArraySelection' was executed in %ld seconds\n", timeSelection);
    printf("The function 'sortArray' was executed in %ld seconds\n", timeSort);

    return 0;
}