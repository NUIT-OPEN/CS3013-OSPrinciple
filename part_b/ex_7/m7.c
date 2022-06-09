#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *sf = fopen("/etc/inittab", "r");
    off_t offset = lseek(fileno(sf), 0, SEEK_END);
    printf("%ld\n", offset);

    return 0;
}