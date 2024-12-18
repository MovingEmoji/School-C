//Naoyda Iida
#include <stdio.h>

#define MAX_SIZE 21

int main(void) {
    char s1[MAX_SIZE], s2[MAX_SIZE];
    printf("Please input 2 strings\n");
    scanf("%s", &s1);
    scanf("%s", &s2);
    int i, count = 0;
    for(i = 0; s1[i] != '\0'; i++) {
        count++;
    }
    for(i = 0; s2[i] != '\0'; i++) {
        count++;
    }
    char s3[count + 1];
    count = 0;
    for(i = 0; s1[i] != '\0'; i++) {
        s3[count] = s1[i];
        count++;
    }
    for(i = 0; s2[i] != '\0'; i++) {
        s3[count] = s2[i];
        count++;
    }
    s3[count] = '\0';
    printf("%s\n", s3);
    return 0;
}
/*
abc
def
abcdef

*/