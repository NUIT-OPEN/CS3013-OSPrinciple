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

#define G_LOCK 1

int main() {
    int fd[2];

    int *fd_r = &fd[0];
    int *fd_w = &fd[1];

    pipe(fd);

    char buffer[1024];
    // init lock.
    lockf(G_LOCK, F_LOCK, 0);

    int pid_child = fork();
    if (!pid_child) {
        // is children.
        pipe_put(*fd_w, "I am your son!");
        lockf(G_LOCK, F_LOCK, 0);
        pipe_get(*fd_r, buffer, sizeof(buffer));
        printf("[child] recv: %s\n", buffer);
    } else {
        // is parent.
        pipe_get(*fd_r, buffer, sizeof(buffer));
        lockf(G_LOCK, F_ULOCK, 0);
        printf("[parent] recv: %s\n", buffer);
        pipe_put(*fd_w, "I am your father!");
        wait();
    }

    return 0;
}
