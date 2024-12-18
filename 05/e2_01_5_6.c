//Naoyda Iida
#include <stdio.h>

struct Car {
    int num;
    double gas;
};


int main(void) {
    struct Car c1;
    c1.num = 1234;
    c1.gas = 20.0;
    struct Car c2 = {5678, 40.0};
    struct Car c3;
    scanf("%d", &c3.num);
    scanf("%lf", &c3.gas);
    printf("[c1] num=%d, gas=%.1f\n", c1.num, c1.gas);
    printf("[c2] num=%d, gas=%.1f\n", c2.num, c2.gas);
    printf("[c3] num=%d, gas=%.1f\n", c3.num, c3.gas);
    return 0;
}
/*
[c1] num=1234, gas=20.0
[c2] num=5678, gas=40.0
[c3] num=9123, gas=60.0

*/