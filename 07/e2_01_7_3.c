//Naoyda Iida
#include <stdio.h>
#include <pthread.h>

typedef struct Data {
    int val;
    char name[64];
} Data;

void *threadA(void *arg) {
    Data *d = (Data *) arg;
    printf("[Thread A] %d %s\n",d->val,d->name);
    d->val = 200;
    d->name[0] = *"alice";
}

int main(void) {
    pthread_t a;
    Data data = {100, "Alice"};
    pthread_create(&a, NULL, threadA, (void *)&data);
    pthread_join(a, NULL);
    printf("[main] %d %s\n",data.val,data.name);
}
/*
Naoya Iida

*/