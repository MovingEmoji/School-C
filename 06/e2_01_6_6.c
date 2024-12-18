//Naoyda Iida
#include <stdio.h>
#include <string.h>

#define MAXSIZE 256

int main(int argc, char *argv[]) {
    if(argc == 1 || argc > 3) {
        fprintf(stderr, "[Usage] >a.exe in_file [out_file]");
        return -1;
    }
    FILE *src, *rst;
    if((src = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        return -1;
    }
    char rstname[MAXSIZE];
    if(argc == 2) {
        sprintf(rstname, "line_%s", argv[1]);
    } else if(argc == 3) {
        sprintf(rstname, "%s", argv[2]);
    }
    if((rst = fopen(rstname, "w")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        return -1;
    }
    char buf[MAXSIZE];
    int cnt = 1;
    while(fgets(buf, MAXSIZE, src) != NULL) {
        fprintf(rst, "%d:%s",cnt,buf);
        cnt++;
    }
    fclose(src);
    fclose(rst);
    return 0;
}
/*
PS P:\C-Lang> .\a.exe hoge.txt foo.txt
PS P:\C-Lang> .\a.exe hoge.txt
PS P:\C-Lang> .\a.exe
[Usage] >a.exe in_file [out_file]
PS P:\C-Lang> .\a.exe a b c
[Usage] >a.exe in_file [out_file]


*/