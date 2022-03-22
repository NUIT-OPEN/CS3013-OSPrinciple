#include <unistd.h>
#include <stdio.h>

int main() {
    int a_pid, b_pid, c_pid, d_pid;
    a_pid = getpid();

    printf("a pid: %d, parent pid: %d\n", a_pid, getppid());
    b_pid = fork();
    if (!b_pid) {
        printf("b pid: %d, parent pid: %d\n", getpid(), getppid());
        c_pid = fork();
        if (!c_pid) {
            printf("c pid: %d, parent pid: %d\n", getpid(), getppid());
            d_pid = fork();
            if (!d_pid) {
                printf("d pid: %d, parent pid: %d\n", getpid(), getppid());
                return 0;
            }
            wait();
            return 0;
        }
        wait();
        return 0;
    }
    wait();
    return 0;
}
