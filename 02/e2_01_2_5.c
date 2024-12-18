//Naoyda Iida
#include <stdio.h>

#define MAX_SIZE 256

int main(void) {
    char str[MAX_SIZE];
    char search[MAX_SIZE];
    printf("Input string\n");
    scanf("%[a-zA-Z ]", &str);
    printf("Input Search Character\n");
    scanf("%s", &search);
    printf("%s\n", str);
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == search[0]) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
/*
Input string
c ensyuu ha tanoshii
Input Search Character
n
c ensyuu ha tanoshii
   *          *

*/