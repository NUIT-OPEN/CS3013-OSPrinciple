#include <unistd.h>
#include <stdio.h>

int main() {
    int p_pid, c1_pid, c2_pid;
    p_pid = getpid();

    c1_pid = fork();
    if (!c1_pid) {
        for (int i = 0; i < 50; i++) {
            printf("Son %d", i);
        }

        return 0;
    }

    c2_pid = fork();
    if (!c2_pid) {
        for (int i = 0; i < 50; i++) {
            printf("Daughter %d", i);
        }

        return 0;
    }

    for (int i = 0; i < 50; i++) {
        printf("Father %d", i);
    }

    wait(NULL);
    wait(NULL);

    return 0;
}
