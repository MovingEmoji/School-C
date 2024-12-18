//Naoyda Iida
#include <stdio.h>
int main() {
    int array[10] = {3, 29, 14, 7, 10, 33, 6, 23, 19, 1};
    int *p = array;
    int *maxPtr = p;
    int *minPtr = p;
    for (int i = 1; i < 10; i++) {
        if(array[i] > *maxPtr) {
            maxPtr = &array[i];
        }
        if(array[i] < *minPtr) {
            minPtr = &array[i];
        }
    }
    printf("MAX: %d \n", *maxPtr);
    printf("MIN: %d \n", *minPtr);
    return 0;
}

/*
MAX: 33 
MIN: 1 

*/