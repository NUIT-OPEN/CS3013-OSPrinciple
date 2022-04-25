#include <pthread.h>
#include <stdio.h>

void *child(void *param) {
    printf("Transfer Parameter: %s\n", (char *)param);
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, child, "Test content.");
    pthread_join(tid, NULL);
    return 0;
}

