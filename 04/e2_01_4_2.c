//Naoya Iida
#include <stdio.h>
#define NUMBER 5

static int count = 0;

int fact(int a);

int fact(int a) {
    count++;
    printf("count=%d, fact(%d)\n", count, a);
    if (a > 1)
        return a * fact(a - 1);
    else
        return 1;
    
}

int main(void) {
    int x = NUMBER;
    printf("%d! = %d\n", x, fact(x));
    return 0;
}
/*
count=1, fact(5)
count=2, fact(4)
count=3, fact(3)
count=4, fact(2)
count=5, fact(1)
5! = 120

*/