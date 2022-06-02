#include <stdio.h>

int main() {
    FILE *f = fopen("/etc/passwd", "r");
    char *buffer;
    size_t buffer_size;
    ssize_t read_size;

    int i = 0;
    while ((read_size = getline(&buffer, &buffer_size, f)) != EOF) {
        printf("line %d: %s", ++i, buffer);
    }

    return 0;
}
