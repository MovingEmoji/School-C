//Naoyda Iida
#include <stdio.h>
#include <pthread.h>

int cnt = 0;

void *threadA(void *arg) {
    int i, tmp;
    for(i = 0; i < 1000000; i++) {
        tmp = cnt;
        cnt = tmp + 1;
    }
}

void *threadB(void *arg) {
    int i, tmp;
    for(i = 0; i < 1000000; i++) {
        tmp = cnt;
        cnt = tmp + 1;
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
cnt = 1093260
PS N:\E201\C-Lang> ./a.exe
cnt = 1025323
PS N:\E201\C-Lang> ./a.exe
cnt = 1073671
PS N:\E201\C-Lang> ./a.exe
cnt = 1380035

*/