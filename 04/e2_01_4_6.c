//Naoyda Iida
#include <stdio.h>

void swap(int *px, int *py);

void swap(int *px, int *py){
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
int main() {
    int x = 1, y = 2;
    printf("x=%d y=%d\n", x, y);
    swap(&x, &y);
    printf("x=%d y=%d\n", x, y);
}
/*
x=1 y=2
x=2 y=1

*/