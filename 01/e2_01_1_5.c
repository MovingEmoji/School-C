//Naoyda Iida
#include <stdio.h>

int main(void) {
    int kouka[] = {500, 100, 50, 10, 5, 1};
    const int length = 6;
    int i, change;
    printf("Change (Yen) = ");
    scanf("%d", &change);
    for(i = 0; i < length; i++) {
        int maisu = change / kouka[i];
        printf("%d Yen = %d\n", kouka[i], maisu);
        change = change - kouka[i] * maisu;
    }
    return 0;
}
/*
500 Yen = 1
100 Yen = 4
50 Yen = 1
10 Yen = 2
5 Yen = 0
1 Yen = 3

*/