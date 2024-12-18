//Naoyda Iida
#include <stdio.h>

int euclid (int a, int b);

int main(void) {
    int a, b;
    while(1) {
        if(scanf("%d", &a) < 0) {
            break;
        }
        if(scanf("%d", &b) < 0) {
            break;
        }
        printf("%d\n", euclid(a, b));
    }
    return 0;
}

int euclid (int a, int b) {
    if(a % b == 0) {
        return b;
    } else {
        return euclid(b, a % b);
    }
}

/*
4 12
4
12 4
4
876 204 
12
^Z

*/