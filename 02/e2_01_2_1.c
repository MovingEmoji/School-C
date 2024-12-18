//Naoyda Iida
#include <stdio.h>

int main(void) {
    char str[256];
    int i;
    printf("please input string\n");
    while(scanf("%s",&str) != EOF) {
        int count = 0;
        for(i = 0; str[i] != '\0'; i++) {
            count++;
        }
        printf("length: %d\n", count);
        printf("please input string\n");
    }
    
    return 0;
}
/*
please input string
abc
length: 3
please input string
abcdef
length: 6
please input string
^Z

*/