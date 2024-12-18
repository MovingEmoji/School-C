//Naoyda Iida
#include <stdio.h>

#define MAX_SIZE 256

char convert(char c);

int main(void) {
    char scan[MAX_SIZE];
    while(scanf("%s", scan) != EOF) {
        int i;
        for(i = 0; scan[i] != '\0'; i++) {
            printf("%c", convert(scan[i]));
        }
        printf("\n");
    }
    return 0;
}

char convert(char c) {
    char result = c;
    if('a' <= c && c <= 'z') {
        result = result - 'a' + 'A';
    }
    return result;
}
/*
abcDEF#!
ABCDEF#!
^Z

*/