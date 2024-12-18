//Naoyda Iida
#include <stdio.h>

#define MAX_SIZE 256

int main(void) {
    char str[MAX_SIZE];
    char search[MAX_SIZE];
    char replace[MAX_SIZE];
    printf("Input string\n");
    scanf("%[a-zA-Z ]", str);
    printf("Input Search Character\n");
    scanf("%s", search);
    printf("Input Replace String\n");
    scanf("%s", replace);
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == search[0]) {
            printf("%s", replace);
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    
    return 0;
}
/*
Input string
abcde abcde
Input Search Character
c
Input Replace String
java
abjavade abjavade

*/