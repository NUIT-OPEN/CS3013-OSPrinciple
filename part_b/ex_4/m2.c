#include <pthread.h>
#include <stdio.h>

#define STU_NUM_DEF "<stu_number_define>"
#define STU_NUM_MOD "<stu_number_modify>"

pthread_key_t a;

void *child1(void *_) {
    printf("[%lu] This is child 1.\n", (unsigned long) pthread_self());
    return NULL;
}

void *child2(void *_) {
    printf("[%lu] This is child 2.\n", (unsigned long) pthread_self());

    if (!pthread_getspecific(a)) {
        pthread_setspecific(a, STU_NUM_DEF);
        printf("[define] a = %s\n", (char *) pthread_getspecific(a));
    }

    pthread_setspecific(a, STU_NUM_MOD);
    printf("[modify] a = %s\n", (char *) pthread_getspecific(a));

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

    return 0;
}
