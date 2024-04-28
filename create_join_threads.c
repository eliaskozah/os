#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void* myturn(void *arg) {
    int *ip = (int *)malloc(sizeof(int));
    *ip = 7;
    for(int i = 0; i < 8; i++) {
        sleep(1);
        printf("My turn! %d %d\n", i, *ip);
         (*ip)++;
    }
    return ip;
}

void yourturn() {
    for(int i = 0; i < 5; i++) {
        sleep(1);
        printf("Your turn! %d\n", i);
       
    }
}

int main() {
    pthread_t newthread;
    int *v;
    pthread_create(&newthread, NULL, myturn, NULL);
    yourturn();
    pthread_join(newthread, (void*)&v);
    printf("thread's done: v=%d\n", *v);
}