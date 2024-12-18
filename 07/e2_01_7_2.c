//Naoyda Iida
#include <stdio.h>
#include <pthread.h>

void *threadA(void *arg) {
    int cnt = *(int *)arg;
    printf("cnt = %d\n",cnt);
}

int main() {
    int cnt = 100;
    pthread_t a;
    pthread_create(&a, NULL, threadA, (void *)&cnt);
    pthread_join(a, NULL);
}
/*
cnt = 100

*/