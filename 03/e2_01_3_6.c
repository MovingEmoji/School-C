//Naoyda Iida
#include <stdio.h>

#define MAX_SIZE 256

int str_len(char str[]);
void str_rev(char str[], char dst[]);

int main(void) {
    char src[MAX_SIZE];
    char dst[MAX_SIZE];
    scanf("%s", src);
    str_rev(src, dst);
    printf("%s\n", dst);
    return 0;
}

int str_len(char str[]) {
    int i, length = 0;
    for(i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

void str_rev(char src[], char dst[]) {
    int i;
    for(i = 0; i < str_len(src); i++) {
        dst[i] = src[str_len(src) - i -1];
    }
    dst[i] = '\0';
}
/*
abcde
edcba

*/