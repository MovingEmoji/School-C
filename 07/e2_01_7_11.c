//Naoyda Iida
#include <stdio.h>
#include <pthread.h>

int x = 0, y = 0;
pthread_mutex_t key_x = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t key_y = PTHREAD_MUTEX_INITIALIZER;

void *threadA(void *arg) {
    int i;
    for(i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&key_x);
        //printf("[ThreadA] lock x\n");
        pthread_mutex_lock(&key_y);
        //printf("[ThreadB] lock y\n");
        x++;
        y++;
        pthread_mutex_unlock(&key_x);
        //printf("[ThreadA] unlock x\n");
        pthread_mutex_unlock(&key_y);
        //printf("[ThreadA] unlock y\n");
    }
}

void *threadB(void *arg) {
    int i;
    for(i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&key_x);
        //printf("[ThreadB] lock x\n");
        pthread_mutex_lock(&key_y);
        //printf("[ThreadB] lock y\n");
        x++;
        y++;
        pthread_mutex_unlock(&key_x);
        //printf("[ThreadB] unlock x\n");
        pthread_mutex_unlock(&key_y);
        //printf("[ThreadB] unlock y\n");
    }
}

int main() {
    pthread_t a, b;
    pthread_create(&a, NULL, threadA, NULL);
    pthread_create(&b, NULL, threadB, NULL);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
}
/*
x = 2000000
y = 2000000
*/