#include <stdio.h>

int x;

int f(void);

int f(void) {
    x++;
    return x;
}
int main(void) {
    printf("answer=%d\n", f());
    printf("answer=%d\n", f());
    printf("answer=%d\n", f());
    return 0;
}