#include <stdio.h>

int main() {
    FILE *f = fopen("/etc/passwd", "r");
    char *buffer;
    size_t buffer_size;
    ssize_t read_size;

    FILE *of = fopen("./qq.txt", "w");

    int i = 0;
    while ((read_size = getline(&buffer, &buffer_size, f)) != EOF) {
        i++;
        if (i >= 2 && i <= 5)
            fprintf(of, "line %d: %s", i, buffer);
    }

    fclose(of);

    return 0;
}
