//Naoyda Iida
#include <stdio.h>

void my_sort(int a[], int n);

int main(void) {
    int a[] = {4,8,1,7,9,2,6,3,0,5};
    int len = 10;
    int i;
    printf("org: ");
    for(i = 0; i < len; i++) {
        if(i != len - 1) {
            printf("%d,", a[i]);
        } else {
            printf("%d\n", a[i]);
        }
    }
    my_sort(a, len);
    printf("sorted: ");
    for(i = 0; i < len; i++) {
        if(i != len - 1) {
            printf("%d,", a[i]);
        } else {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}

void my_sort(int a[], int n) {
    int i;
    while(1) {
        int bool = 0;
        for(i = n - 1; i > 0; i--) {
            if(a[i] < a[i - 1]) {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                bool = 1;
            }
        }
        if(bool == 0) {
            break;
        }
    }
}
/*
org: 4,8,1,7,9,2,6,3,0,5
sorted: 0,1,2,3,4,5,6,7,8,9

*/