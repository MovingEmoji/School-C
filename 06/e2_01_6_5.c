//Naoyda Iida
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc < 4) {
        fprintf(stderr, "[Usage] >a.exe str1 str2 str3\n");
        return -1;
    }
    int i;
    for(i = 1; i < argc; i++) {
        printf("%s", argv[i]);
    }
    printf("\n");
    return 0;
}
/*
PS P:\C-Lang> .\a.exe abc de   
[Usage] >a.exe str1 str2 str3
PS P:\C-Lang> .\a.exe abc de f 
abcdef

*/