#include <unistd.h>
#include <stdio.h>

int main() {
    int p_pid, c1_pid, c2_pid;
    p_pid = getpid();

    c1_pid = fork();
    if (!c1_pid) {
        printf("b no kotoba\n");
        return 0;
    }

    c2_pid = fork();
    if (!c2_pid) {
        printf("c no kotoba\n");
        return 0;
    }

    printf("a no kotoba\n");

    return 0;
}
