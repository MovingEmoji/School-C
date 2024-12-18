//Naoyda Iida
#include <stdio.h>

#define MAX_SIZE 256

int str_len(char str[]);

int main(void) {
    char scan[MAX_SIZE];
    while(scanf("%s", scan) != EOF) {
        printf("%d\n", str_len(scan));
    }
    return 0;
}

int str_len(char str[]) {
    int i, length = 0;
    for(i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

/*
abcDE
5
AB!
3
^Z

*/