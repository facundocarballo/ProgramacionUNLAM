#include <stdio.h>

const short* getAddresOf(const short array[], const int index) {
    printf("Value = %d\n", array[index]);
    return &array[index];
}

int main() {
    short array[] = {5,3,1,5,7,32,65,23};
    for (short i = 0; i < 8; i++) {
        printf("The addres of array[%d] is: %p\n", i, getAddresOf(array, i));
    }
    return 0;
}