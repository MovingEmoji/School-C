//Naoyda Iida
#include <stdio.h>

int main(void) {
    char str[256];
    int i;
    printf("please input string\n");
    while(scanf("%s", str) != EOF) {
        int count = 0;
        for(i = 0; str[i] != '\0'; i++) {
            count++;
        }
        for(i = count - 1; i >= 0; i--) {
            printf("%c", str[i]);
        }
        printf("\n");
        printf("please input string\n");
    }
    
    return 0;
}
/*
please input string
abc
cba
please input string
abcdef
fedcba
please input string
^Z

*/