//Naoyda Iida
#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 256

int main(void) {
    char str[1000];
    int freq[ASCII_SIZE] = {0};
    scanf("%s", str);
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }
    for(i = 0; i < ASCII_SIZE; i++) {
        //printf("%c %d\n", i, freq[i]);
        if(freq[i] != 0) {
            printf("%c %d\n", i, freq[i]);
        }
    }
    return 0;
}
/*
* 6
- 4
/ 1
1 2
2 2
3 2
4 1
= 4
f 6
g 3
h 3
u 2

*/