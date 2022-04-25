#include <pthread.h>
#include <stdio.h>

pthread_key_t a;

void *child1(void *_) {
    printf("[%lu] This is child 1.\n", (unsigned long) pthread_self());
    pthread_setspecific(a, "child1");
    printf("[child1] a = %s\n", (char *) pthread_getspecific(a));
    return NULL;
}

void *child2(void *_) {
    printf("[%lu] This is child 2.\n", (unsigned long) pthread_self());
    pthread_setspecific(a, "child2");
    printf("[child2] a = %s\n", (char *) pthread_getspecific(a));
    return NULL;
}

int main() {
    pthread_t t_id[2];
    void *func[] = {child1, child2};

    pthread_key_create(&a, NULL);

    for (int i = 0; i < 2; ++i)
        pthread_create(&t_id[i], NULL, func[i], NULL);

    for (int i = 0; i < 2; ++i)
        pthread_join(t_id[i], NULL);

    pthread_key_delete(a);

    return 0;
}
