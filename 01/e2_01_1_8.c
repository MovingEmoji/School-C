//Naoyda Iida
#include <stdio.h>

int main(void) {
    const int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numscount[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    const int numslength = 10;
    int data[50];
    const int datalength = 50;
    int count = 0;
    int i, j;
    printf("Input data: \n");
    for(i = 0; i < datalength; i++) {
        int num;
        scanf("%d", &num);
        if(num < 0) {
            break;
        }
        count ++;
        data[i] = num;
        numscount[data[i]]++;
    }
    for(i = 0; i < numslength; i++) {
        printf("%d | ", nums[i]);
        for(j = 0; j < numscount[nums[i]]; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
/*
0 | **
1 | ***
2 | **
3 | **
4 | ********
5 | ****
6 | *
7 | ****
8 | ***
9 | **

*/