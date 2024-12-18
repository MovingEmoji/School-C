//Naoyda Iida
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 3

int * create_array(int x, int y, int z);

int * create_array(int x, int y, int z) {
    int *pa = (int *)malloc(sizeof(int) * ARRAY_SIZE);
    if(pa == NULL){
        return NULL;
    }
    int *ptr = pa;
    *ptr = x;
    ptr++;
    *ptr = y;
    ptr++;
    *ptr = z;
    return pa;
}
int main() {
    int *p = create_array(1, 2, 3);
    if(p == NULL) {
        fprintf(stderr, "Cannot allocate memory!");
        return -1;
    }
    int i;
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", *(p+i));
    }
    return 0;
}
/*
1
2
3

*/