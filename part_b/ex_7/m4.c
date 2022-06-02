#include <stdio.h>

int main() {
    FILE *f = fopen("./test2", "w");
    fprintf(f, "Hello,welcome to hustwenhua!");

    return 0;
}
