#include <unistd.h>
#include <stdio.h>

int main() {
    int p_pid, c1_pid, c2_pid;
    p_pid = getpid();

    c1_pid = fork();
    if (!c1_pid) {
        printf("child_1 id: %d\n", getpid());
        return 0;
    }

    c2_pid = fork();
    if (!c2_pid) {
        printf("child_2 id: %d\n", getpid());
        return 0;
    }

    printf("parent id: %d\n", p_pid);
    wait(NULL);
    wait(NULL);

    return 0;
}
