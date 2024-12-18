//Naoyda Iida
#include <stdio.h>

int main(void) {
    const int a[] = {1, 11, 8, -3, 27, 39, 31, 50, -7, 15};
    const int length = 10;
    int num, i;
    printf("a = [");
    for(i = 0; i< length; i++) {
        if(i < length -1) {
            printf("%d,", a[i]);
        }
    }
    printf("]\n");
    printf("Please Input data\n");
    while(scanf("%d", &num) != EOF) {
        
        int found = 0;
        for(i = 0; i < length; i++) {
            if(a[i] == num) {
                found = 1;
                printf("Found! a[%d]\n", i);
                break;
            }
        }
        if(found == 0) {
            printf("NotFound...\n");
        }
        printf("Please Input data\n");
    }
    return 0;
}
/*
Please Input data
-7
Found! a[8]
Please Input data
50
Found! a[7]
Please Input data
13
NotFound...
Please Input data
^Z

*/