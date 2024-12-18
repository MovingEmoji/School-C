//Naoyda Iida
#include <stdio.h>

int main(void) {
    int data[10];
    const int length = 10;
    int count = 0;
    int i, max, second, min;
    for(i = 0; i < length; i++) {
        int num;
        printf("Please input data ");
        scanf("%d", &num);
        if(num < 0) {
            break;
        }
        count++;
        data[i] = num;
    }
    printf("Input data:");
    max, second = 0;
    min = -1;
    //MinMax
    for(i = 0; i < count; i++) {
        if(max <= data[i]) {
            max = data[i];
        }

        if(min == -1) {
            min = data[i];
        } else {
            if(min >= data[i]) {
                min = data[i];
            }
        }
        printf(" %d",data[i]);
    }
    //Second
    for(i = 0; i < count; i++) {
        if(max > data[i]) {
            if(second <= data[i]) {
                second = data[i];
            }
        }
    }
    if(count > 0) {
        printf("\nMax=%d\n", max);
        printf("Max2=%d\n", second);
        printf("Min=%d\n", min);
    }
    return 0;
}
/*
Please input data 10
Please input data 20
Please input data 5
Please input data 38
Please input data -1
Input data: 10 20 5 38
Max=38
Max2=20
Min=5

*/