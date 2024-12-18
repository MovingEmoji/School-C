//Naoyda Iida
#include <stdio.h>
#include <pthread.h>

int cnt = 0;
pthread_mutex_t key = PTHREAD_MUTEX_INITIALIZER;

void increment(void) {
    pthread_mutex_lock(&key);
    cnt++;
    pthread_mutex_unlock(&key);
}

void *threadA(void *arg) {
    int i;
    for(i = 0; i < 1000000; i++) {
        increment();
    }
}

void *threadB(void *arg) {
    int i;
    for(i = 0; i < 1000000; i++) {
        increment();
    }
}

int main() {
    pthread_t a, b;
    pthread_create(&a, NULL, threadA, NULL);
    pthread_create(&b, NULL, threadB, NULL);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    printf("cnt = %d\n", cnt);
}
/*
PS N:\E201\C-Lang> ./a.exe        
cnt = 2000000
PS N:\E201\C-Lang> ./a.exe
cnt = 2000000
PS N:\E201\C-Lang> ./a.exe
cnt = 2000000
PS N:\E201\C-Lang> ./a.exe
cnt = 2000000

*/