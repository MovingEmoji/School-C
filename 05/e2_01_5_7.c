//Naoyda Iida
#include <stdio.h>

typedef struct Car{
    int num;
    double gas;
    char name[64];
} Car;

void change_num(Car *p);

void change_num(Car *p) {
    printf("change_num()\n");
    p -> num = 5678;
}

void change_name(Car *p) {
    printf("change_name()\n");
    p -> name[0] = *"Y";
}



int main(){
    Car c1 = {1234, 20.0, "TOYOTA"};
    printf("num=%d, gas=%.6f, name=%s\n", c1.num, c1.gas, c1.name);
    change_num(&c1);
    change_name(&c1);

    printf("num=%d, gas=%.6f, name=%s\n", c1.num, c1.gas, c1.name);
}

/*
num=1234, gas=20.000000, name=TOYOTA
change_num()
change_name()
num=5678, gas=20.000000, name=YOYOTA

*/