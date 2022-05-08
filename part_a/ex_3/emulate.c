#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int remain_ticket_num = 10;
pthread_mutex_t g_mutex;
pthread_cond_t g_cond;

void *buy_ticket(void *_) {
    while (remain_ticket_num > 0) {
        printf("[%lu] Buying...\n", (unsigned long) pthread_self());
        fflush(stdout);

        sleep(1);

        pthread_mutex_lock(&g_mutex);
        if (remain_ticket_num)
            remain_ticket_num--;
        else {
            pthread_mutex_unlock(&g_mutex);
            break;
        }
        pthread_mutex_unlock(&g_mutex);

        printf("[%lu] Bought, remain %d tickets.\n", (unsigned long) pthread_self(), remain_ticket_num);
        fflush(stdout);
    }

    return NULL;
}

int main() {
    pthread_t tid[3];

    pthread_mutex_init(&g_mutex, NULL);
    pthread_cond_init(&g_cond, NULL);

    for (int i = 0; i < 3; ++i) {
        pthread_create(&tid[i], NULL, buy_ticket, NULL);
    }

    for (int i = 0; i < 3; ++i) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}

