#include <stdio.h>
#include <unistd.h>
#include <string.h>

void pipe_put(int fd, char *data) {
    lockf(fd, F_LOCK, 0);
    write(fd, data, strlen(data) + 1);
    lockf(fd, F_ULOCK, 0);
}

void pipe_get(int fd, char *buffer, int size) {
    lockf(fd, F_LOCK, 0);
    read(fd, buffer, size);
    lockf(fd, F_ULOCK, 0);
}

int main() {
    int fd[2];

    int *fd_r = &fd[0];
    int *fd_w = &fd[1];

    pipe(fd);

    char buffer[1024];

    int pid_child_1 = fork();
    if (!pid_child_1) {
        // is children 1.
        pipe_put(*fd_w, "Child 1 is sending a message!");
        return 0;
    }

    int pid_child_2 = fork();
    if (!pid_child_2) {
        // is children 2.
        pipe_get(*fd_r, buffer, sizeof(buffer));
        printf("[child_2] recv: %s\n", buffer);
        return 0;
    }

    wait();
    wait();

    return 0;
}
