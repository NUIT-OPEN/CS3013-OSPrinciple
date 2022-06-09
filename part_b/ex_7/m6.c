#include <stdio.h>

int main() {
    FILE *sf = fopen("/etc/inittab", "r");
    for (int i = 0; i < 100; ++i)
        printf("%c", fgetc(sf));
    printf("\n");

    return 0;
}