//Naoyda Iida
#include <stdio.h>
#include <pthread.h>

int cnt = 0;
pthread_mutex_t key = PTHREAD_MUTEX_INITIALIZER;

void *threadA(void *arg) {
    int i, tmp;
    pthread_mutex_lock(&key);
    for(i = 0; i < 1000000; i++) {
        tmp = cnt;
        cnt = tmp + 1;
    }
    pthread_mutex_unlock(&key);
}

void *threadB(void *arg) {
    int i, tmp;
    pthread_mutex_lock(&key);
    for(i = 0; i < 1000000; i++) {
        tmp = cnt;
        cnt = tmp + 1;
    }
    pthread_mutex_unlock(&key);
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