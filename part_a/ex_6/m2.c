#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *src_file = "/etc/passwd";
    char *dest_file = "./test5";

    FILE *sf = fopen(src_file, "r");
    FILE *df = fopen(dest_file, "w");

    char *buf = malloc(10 * 1024);
    char *username;
    while (fgets(buf, 10 * 1024, sf)) {
        username = strtok(buf, ":");
        fprintf(df, "%s\n", username);
        printf("%s ", username);
    }

    return 0;
}