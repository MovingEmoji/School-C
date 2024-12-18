//Naoyda Iida
#include <stdio.h>
#include <string.h>

#define BUFSIZE 256

void mygrep(char *filename, char *word);

void mygrep(char *filename, char *word) {
    FILE *src;
    if((src = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", filename);
    } else {
        char buf[BUFSIZE];
        while(fgets(buf, BUFSIZE, src) != NULL) {
            char *result;
            if((result = strstr(buf, word)) != NULL) {
                printf("%s", buf);
            }
        }
    }
}

int main(void) {
    char filename[BUFSIZE], word[BUFSIZE];
    printf("filename=");
    scanf("%s", filename);
    printf("word=");
    scanf("%s", word);
    mygrep(filename, word);
    return 0;
}
/*
PS P:\C-Lang> .\a.exe
filename=log
word=a
Can't open file log
PS P:\C-Lang> .\a.exe
filename=log.txt
word=chrome
PS P:\C-Lang> .\a.exe
filename=log.txt
word=Chrome
108.81.70.158 - - [16/Jun/2015:13:59:34 +0000] "GET /item/electronics/3717 
HTTP/1.1" 200 86 "-" "Mozilla/5.0 (Windows NT 6.0) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11"
176.33.96.225 - - [16/Jun/2015:13:59:35 +0000] "GET /category/cameras HTTP/1.1" 200 88 "-" "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11"
192.75.60.93 - - [16/Jun/2015:13:59:35 +0000] "POST /search/?c=Giftcards+Electronics HTTP/1.1" 200 127 "/category/giftcards" "Mozilla/5.0 (Windows NT 
6.1; WOW64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11"
172.171.186.182 - - [16/Jun/2015:13:59:35 +0000] "POST /search/?c=Software+Networking HTTP/1.1" 200 80 "-" "Mozilla/5.0 (Windows NT 6.0) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11"

*/