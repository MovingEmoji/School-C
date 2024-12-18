//Naoyda Iida
#include <stdio.h>

int find_element(int *ary, int size, int target);

int find_element(int *ary, int size, int target) {
    int i; 
    int *ptr = ary;
    for(i = 0; i < size; i++) {
        if(*ptr == target) {
            return i;
        }
        ptr++;
    }
    return -1;
}

int main(void) {
    int array[10] = {15, 22, 8, 19, 31, 7, 14, 40, 3, 12};
    int target;
    printf("[SearchNumber]\n");
    scanf("%d", &target);
    int result = find_element(array, 10, target);
    if(result < 0) {
        printf("Not Found\n");
    } else {
        printf("Found index = %d", result);
    }
    return 0;
}
/*
[SearchNumber]
19
Found index = 3

P:\C-Lang> .\a.exe
[SearchNumber]
100
Not Found

*/