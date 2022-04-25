#include <unistd.h>
#include <stdio.h>

int main() {
    int a = 3;
    printf("a=%d", a);

    int p_pid, c1_pid, c2_pid;
    p_pid = getpid();
    c1_pid = fork();
    c2_pid = fork();

    return 0;
}
