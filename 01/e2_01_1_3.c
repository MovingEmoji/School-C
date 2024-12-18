//Naoyda Iida
#include <stdio.h>

int main(void) {
    double weight, height;
    while(scanf("%lf %lf", &weight, &height) != EOF) {
        height = height / 100.0 * height / 100;
        printf("BMI= %lf\n", weight / height);
    }
    return 0;
}
/*
70 170
BMI= 24.221453
60 160
BMI= 23.437500
^Z

*/