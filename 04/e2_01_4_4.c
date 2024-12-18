//Naoyda Iida
#include <stdio.h>

int main(void) {
    int i1, i2, i3;
    char c1, c2, c3;
    double d1, d2, d3;
    printf("address= i1 %p\n", &i1);
    printf("address= i2 %p\n", &i2);
    printf("address= i3 %p\n", &i3);
    printf("address= c1 %p\n", &c1);
    printf("address= c2 %p\n", &c2);
    printf("address= c3 %p\n", &c3);
    printf("address= d1 %p\n", &d1);
    printf("address= d2 %p\n", &d2);
    printf("address= d3 %p\n", &d3);

    int array[10];
    printf("sizeof(short)= %d bytes\n", sizeof(short));
    printf("sizeof(int)= %d bytes\n", sizeof(int));
    printf("sizeof(int array)= %d bytes\n", sizeof(array));
    printf("sizeof(long)= %d bytes\n", sizeof(long));
    printf("sizeof(long long int)= %d bytes\n", sizeof(long long int));
    printf("sizeof(char)= %d bytes\n", sizeof(char));
    printf("sizeof(float)= %d bytes\n", sizeof(float));
    printf("sizeof(double)= %d bytes\n", sizeof(double));
    return 0;
}
/*
address= i1 000000000061FE1C
address= i2 000000000061FE18
address= i3 000000000061FE14
address= c1 000000000061FE13
address= c2 000000000061FE12
address= c3 000000000061FE11
address= d1 000000000061FE08
address= d2 000000000061FE00
address= d3 000000000061FDF8
sizeof(short)= 2 bytes
sizeof(int)= 4 bytes
sizeof(int array)= 40 bytes
sizeof(long)= 4 bytes
sizeof(long long int)= 8 bytes
sizeof(char)= 1 bytes
sizeof(float)= 4 bytes
sizeof(double)= 8 bytes

*/