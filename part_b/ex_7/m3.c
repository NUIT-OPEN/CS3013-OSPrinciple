#include <stdio.h>

int main() {
    FILE *f = fopen("/etc/passwd", "r");

    for (int i = 0; i < 100; ++i) {
        printf("%c", fgetc(f));
    }

    return 0;
}
