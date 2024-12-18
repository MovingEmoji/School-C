//Naoyda Iida
#include <stdio.h>

#define MAX(x, y) (x > y ? x : y)

int main(void) {
    int x, y, result;
    scanf("%d", &x);
    scanf("%d", &y);
    result = MAX(x, y);
    printf("%d\n", result);
    double dx, dy, dresult;
    scanf("%lf", &dx);
    scanf("%lf", &dy);
    dresult = MAX(dx, dy);
    printf("%lf\n", dresult);
}
/*
20 30
30
5.6 39.4
39.400000

*/