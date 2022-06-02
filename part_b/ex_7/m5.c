#include <stdio.h>

int main() {
    FILE *f = fopen("/etc/passwd", "r");
    char *buffer;
    size_t buffer_size;
    ssize_t read_size;
    ssize_t total_size = 0;

    while ((read_size = getline(&buffer, &buffer_size, f)) != EOF) {
        total_size += read_size;
        printf("%s", buffer);
    }

    printf("total file size: %ld", total_size);

    return 0;
}
