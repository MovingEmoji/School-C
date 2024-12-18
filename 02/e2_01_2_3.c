//Naoyda Iida
#include <stdio.h>
#define MAX_SIZE 21

int main(void) {
    int i, j=0;
    char x[MAX_SIZE], y[MAX_SIZE];
    printf("Please input string\n");
    scanf("%s", &x);

    for(i = 0; x[i] != '\0'; i++) {
        if('a' <= x[i] && x[i] <= 'z') {
            y[j] = x[i] - 'a' + 'A';
        } else if('A' <= x[i] && x[i] <= 'Z') {
            y[j] = x[i] - 'A' + 'a';
        } else {
            y[j] = x[i];
        }
        j++;
    }
    y[j] = '\0';
    printf("%s\n", y);
}
/*
Please input string
aBcdE!3f
AbCDe!3F

*/