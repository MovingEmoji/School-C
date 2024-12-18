//Naoyda Iida
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

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
    unsigned int sec;
    int nsec;
    double t;
    struct timespec start_time, end_time;

    clock_gettime(CLOCK_REALTIME, &start_time);

    pthread_t a, b;
    pthread_create(&a, NULL, threadA, NULL);
    pthread_create(&b, NULL, threadB, NULL);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    printf("cnt = %d\n", cnt);

    clock_gettime(CLOCK_REALTIME, &end_time);

    sec = end_time.tv_sec - start_time.tv_sec;
    nsec = end_time.tv_nsec - start_time.tv_nsec;
    t = (double)sec + (double)nsec / (1000 * 1000 * 1000);
    t = t * 1000;
    printf("time: %f (ms)\n", t);
    return 0;
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