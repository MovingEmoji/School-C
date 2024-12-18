//Naoyda Iida
#include <stdio.h>

#define MAX_SIZE 7

void mystrcat(char *org1, char *org2, char *new);

void mystrcat(char *org1, char *org2, char *new) {
    char *orgptr = org1;
    char *newptr = new;
    while(*orgptr != '\0') {
        *newptr = *orgptr;
        orgptr++;
        newptr++;
    }
    orgptr = org2;
    while(*orgptr != '\0') {
        *newptr = *orgptr;
        orgptr++;
        newptr++;
    }
    *newptr = '\0';
}

int main(void) {
    char org1[4], org2[4], new[MAX_SIZE];
    printf("org1=");
    scanf("%s", org1);
    printf("org2=");
    scanf("%s", org2);
    mystrcat(org1, org2, new);
    printf("new=%s\n", new);
    return 0;
}
/*
org1=ab  
org2=cde
new=abcde

*/