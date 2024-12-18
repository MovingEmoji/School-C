//Naoyda Iida
#include <stdio.h>

void swap(int x, int y);

void swap(int x, int y){
    int tmp = x;
    x = y;
    y = tmp;
    printf("[swap] address x = %p\n", &x);
    printf("[swap] address y = %p\n", &y);
}
int main() {
    int x = 1, y = 2;
    printf("[main] address x = %p\n", &x);
    printf("[main] address y = %p\n", &y);
    //printf("x=%d y=%d\n", x, y);
    swap(x, y);
    //printf("x=%d y=%d\n", x, y);
}
/*
[main] address x = 000000000061FE1C
[main] address y = 000000000061FE18
[swap] address x = 000000000061FDF0
[swap] address y = 000000000061FDF8

*/