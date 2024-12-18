//Naoyda Iida
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "[Usage] >a.exe num1 num2\n");
        return -1;
    }
    int a = *argv[1] - '0';
    int b = *argv[2] - '0';
    printf("%d + %d = %d\n", a, b, a+b);
    printf("%d - %d = %d\n", a, b, a-b);
    printf("%d * %d = %d\n", a, b, a*b);
    printf("%d / %d = %.1f\n", a, b, (double)a / (double)b);
    return 0;
}
/*
PS P:\C-Lang> .\a.exe 3 5      
3 + 5 = 8
3 - 5 = -2
3 * 5 = 15
3 / 5 = 0.6

*/