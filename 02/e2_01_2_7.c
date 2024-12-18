//Naoyda Iida
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

int main(void) {
    char str[MAX_SIZE];
    char search[MAX_SIZE];
    printf("[Input String]\n");
    while(*fgets(str, sizeof(str), stdin) != EOF) {
        str[strcspn(str, "\n")] = '\0';
        printf("[Search word]\n");
        fgets(search, sizeof(search), stdin);
        search[strcspn(search, "\n")] = '\0';
        char *result;
        result = strstr(str, search);
        //printf("%s", search);
        if(result != NULL) {
            printf("Found!\n");
        } else {
            printf("Not Found\n");
        }
        printf("[Input String]\n");
    }
    return 0;
}
/*
[Input String]
abcdef gh
[Search word]
def
Found!
[Input String]
abcdef gh
[Search word]
bce
Not Found
[Input String]
^Z

*/