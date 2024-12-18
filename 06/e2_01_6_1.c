//Naoyda Iida
#include <stdio.h>

#define SRCNAME "a.txt"
#define RSTNAME "b.txt"
#define BUFSIZE 256

int main(void) {
    FILE *src, *rst;
    if((src = fopen(SRCNAME, "r+")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", SRCNAME);
        return -1;
    }
    if((rst = fopen(RSTNAME, "w")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", SRCNAME);
        return -1;
    }
    char buf[BUFSIZE];
    int cnt = 1;
    while(fgets(buf, BUFSIZE, src) != NULL) {
        fprintf(rst, "%d:%s",cnt,buf);
        cnt++;
    }
    fclose(src);
    fclose(rst);
    return 0;
}
/*
Naoya Iida

*/