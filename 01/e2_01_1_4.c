//Naoyda Iida
#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Please input a, b, c\n");
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    printf("c=");
    scanf("%d", &c);
    printf("SUM=%d\n", a + b + c);
    if(a + b + c >= 200) {
        printf("OK\n");
    } else {
        printf("NG\n");
    }
    printf("AVG=%d\n", (a + b + c) / 3);
    if((a + b + c) / 3 >= 60) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }
    return 0;
}
/*
Please input a, b, c
a=27
b=60
c=90
SUM=177
NG
AVG=59
Fail

*/