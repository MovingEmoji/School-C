//Naoyda Iida
#include <stdio.h>

void mysquare(int *px, int *py);

void mysquare(int *px, int *py) {
    *px = *px * *px;
    *py = *py * *py;
    printf("mysquare()\n");
}
int main() {
    int x = 3, y = 5;
    printf("x=%d y=%d\n", x, y);
    mysquare(&x, &y);
    printf("x=%d y=%d\n", x, y);
}
/*
x=3 y=5
mysquare()
x=9 y=25

*/