//Naoyda Iida
#include <stdio.h>

int sum(int start);

int main(void) {
    char scan;
    while(scanf("%s", &scan) != EOF) {
        int s = sum(scan-'0');
        if(s > 0) {
            printf("%d\n", s);
        } else {
            printf("Error\n");
        }
    }
    return 0;
}

int sum(int start) {
    int result = 0;
    if(start > 0) {
        int i;
        for(i = start; i > 0; i--) {
            result+= i;
        }
    } else {
        result = -1;
    }
    return result;
}

/*
4
10
-1
Error

*/