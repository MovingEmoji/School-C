//Naoyda Iida
#include <stdio.h>

#define MAX_SIZE 256

int fact1(int start);
int fact2(int start);

int main(void) {
    int scan;
    while(scanf("%d", &scan) != -1) {
        int s = fact1(scan);
        if(s > 0) {
            printf("fact1(%d) = %d\n", scan, s);
            int s2 = fact2(scan);
            printf("fact2(%d) = %d\n", scan, s2);
        } else {
            printf("Error\n");
        }
    }
    return 0;
}

int fact1(int start) {
    int result = start;
    if(start > 0) {
        int i;
        for(i = start - 1; i > 0; i--) {
            result*= i;
        }
    } else {
        result = -1;
    }
    return result;
}
int fact2(int start) {
    if(start == 1) {
        return 1;
    } else {
        return start *= fact2(start-1);
    }
}

/*
5
fact1(5) = 120
fact2(5) = 120
10
fact1(10) = 3628800
fact2(10) = 3628800
10000000

*/