#include <pthread.h>
#include <stdio.h>

void *child1(void *_) {

    printf("This is child 1.\n");
    return NULL;
}

void *child2(void *_) {
    printf("This is child 2.\n");
    return NULL;
}

int main() {
    pthread_t t_id[2];
    void *func[] = {child1, child2};

    for (int i = 0; i < 2; ++i)
        pthread_create(&t_id[i], NULL, func[i], NULL);

    for (int i = 0; i < 2; ++i)
        pthread_join(t_id[i], NULL);

    return 0;
}
