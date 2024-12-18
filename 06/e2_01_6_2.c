//Naoyda Iida
#include <stdio.h>

int get_file_size(char *filename);

int get_file_size(char *filename) {
    FILE *src;
    if((src = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", filename);
        return -1;
    }
    int size = 0;
    char c;
    while((c = fgetc(src)) != EOF) {
        size += sizeof(c);
    }
    fclose(src);
    return size;
}

int main(void) {
    
    int size = get_file_size("a.txt");
    printf("%d Bytes\n", size);
    return 0;
}
/*
33 Bytes

*/