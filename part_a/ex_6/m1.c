#include <stdio.h>
#include <stdlib.h>

int main() {
    char *src_file = "./src_file";
    char *dest_file = "./dest_file";

    FILE *sf = fopen(src_file, "r");
    FILE *df = fopen(dest_file, "w");

    char *buf = malloc(10 * 1024);
    fseek(sf, 10 * 1024 * -2, SEEK_END);
    fread(buf, 1024, 10, sf);
    fwrite(buf, 1024, 10, df);

    return 0;
}
