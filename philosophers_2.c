#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma ide diagnostic ignored "cert-msc32-c"
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cert-msc30-c"

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include "printer.h"

#define ERROR_ARGUMENTS_MESSAGE "Usage: philosophers2 [-et min_eating_time max_eating_time] [-tt min_thinking_time max_thinking_time]\n"

int min_thinking_time = 1;
int max_thinking_time = 2;
int min_eating_time = 1;
int max_eating_time = 2;

int get_random(int min, int max);
void* philosopher(void* arg);
void* outsider(void* arg);
void put_down_fork(int fork_id);
void args_interpreter(int argc, char **argv);

pthread_mutex_t mutex;
int philosopher_states[5];  // philosophers states: 0 - eating, 1 - thinking, 2 - waiting for right fork, 3 - waiting for left fork
int fork_states[5];         // forks positions: 0 - table, 1 - left plate, 2 - right plate
pthread_cond_t fork_conditions[5];

int main(int argc, char* argv[]) {
    srand(time(NULL));

    args_interpreter(argc, argv);

    pthread_t philosophers[5];
    int philosopher_ids[5];
    int i;

    pthread_mutex_init(&mutex, NULL);
    for (i = 0;i < 5;i++) {
        pthread_cond_init(&fork_conditions[i], NULL);
        philosopher_states[i] = 1;
        fork_states[i] = 0;
    }
    for (i = 0;i < 4;i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, (void *) &philosopher_ids[i]);
    }
    philosopher_ids[4] = 4;
    pthread_create(&philosophers[4], NULL, outsider, (void *) &philosopher_ids[4]);

    while (1) {
        pthread_mutex_lock(&mutex);
        print(philosopher_states, fork_states);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* philosopher(void* arg) {
    int philosopher_id = *((int *) arg);
    int left_fork_id = philosopher_id;
    int right_fork_id;
    if (philosopher_id == 0) {
        right_fork_id = 4;
    } else {
        right_fork_id = philosopher_id - 1;
    }
    while (1) {
        // start thinking
        pthread_mutex_lock(&mutex);
        philosopher_states[philosopher_id] = 1;
        pthread_mutex_unlock(&mutex);
        sleep(get_random(min_thinking_time, max_thinking_time));
        // stop thinking

        // trying to get left fork
        pthread_mutex_lock(&mutex);
        if (fork_states[left_fork_id] != 0) {
            // waiting for left fork:
            philosopher_states[philosopher_id] = 3;
            pthread_cond_wait(&fork_conditions[left_fork_id], &mutex);
        }
        pthread_mutex_unlock(&mutex);

        // get left fork
        pthread_mutex_lock(&mutex);
        fork_states[left_fork_id] = 2;
        pthread_mutex_unlock(&mutex);

        // wait for a while (better chance for block)
        sleep(1);

        // trying to get right fork
        pthread_mutex_lock(&mutex);
        if (fork_states[right_fork_id] != 0) {
            // waiting for right fork
            philosopher_states[philosopher_id] = 2;
            pthread_cond_wait(&fork_conditions[right_fork_id], &mutex);
        }
        pthread_mutex_unlock(&mutex);

        // get right fork
        pthread_mutex_lock(&mutex);
        fork_states[right_fork_id] = 1;
        philosopher_states[philosopher_id] = 0;
        pthread_mutex_unlock(&mutex);

        // start eating
        sleep(get_random(min_eating_time, max_eating_time));
        // stop thinking

        // put down left fork
        put_down_fork(left_fork_id);
        // put down right fork
        put_down_fork(right_fork_id);
    }
}

void* outsider(void* arg) {
    int philosopher_id = *((int *) arg);
    int left_fork_id = philosopher_id;
    int right_fork_id;
    if (philosopher_id == 0) {
        right_fork_id = 4;
    } else {
        right_fork_id = philosopher_id - 1;
    }
    while (1) {
        // start thinking
        pthread_mutex_lock(&mutex);
        philosopher_states[philosopher_id] = 1;
        pthread_mutex_unlock(&mutex);
        sleep(get_random(min_thinking_time, max_thinking_time));
        // stop thinking

        // trying to get right fork
        pthread_mutex_lock(&mutex);
        if (fork_states[right_fork_id] != 0) {
            // waiting for right fork
            philosopher_states[philosopher_id] = 2;
            pthread_cond_wait(&fork_conditions[right_fork_id], &mutex);
        }
        pthread_mutex_unlock(&mutex);

        // get right fork
        pthread_mutex_lock(&mutex);
        fork_states[right_fork_id] = 1;
        philosopher_states[philosopher_id] = 0;
        pthread_mutex_unlock(&mutex);

        // wait for a while (better chance for block)
        sleep(1);

        // trying to get left fork
        pthread_mutex_lock(&mutex);
        if (fork_states[left_fork_id] != 0) {
            // waiting for left fork:
            philosopher_states[philosopher_id] = 3;
            pthread_cond_wait(&fork_conditions[left_fork_id], &mutex);
        }
        pthread_mutex_unlock(&mutex);

        // get left fork
        pthread_mutex_lock(&mutex);
        fork_states[left_fork_id] = 2;
        pthread_mutex_unlock(&mutex);

        // start eating
        sleep(get_random(min_eating_time, max_eating_time));
        // stop thinking

        // put down left fork
        put_down_fork(left_fork_id);
        // put down right fork
        put_down_fork(right_fork_id);
    }
}


void put_down_fork(int fork_id) {
    pthread_mutex_lock(&mutex);
    // fork on table
    fork_states[fork_id] = 0;
    pthread_cond_broadcast(&fork_conditions[fork_id]);
    pthread_mutex_unlock(&mutex);
}

int get_random(int min, int max) {
    int range = max - min + 1;
    return (rand() % range) + min;
}

void args_interpreter(int argc, char **argv) {
    int temp;
    switch (argc) {
        case 1:
            break;
        case 4:
            if (strcmp(argv[1], "-et") == 0) {
                min_eating_time = atoi(argv[2]);
                max_eating_time = atoi(argv[3]);
                if (min_eating_time > max_eating_time) {
                    temp = min_eating_time;
                    min_eating_time = max_eating_time;
                    max_eating_time = temp;
                }
            } else if (strcmp(argv[1], "-tt") == 0) {
                min_thinking_time = atoi(argv[2]);
                max_thinking_time = atoi(argv[3]);
                if (min_eating_time > max_eating_time) {
                    temp = min_thinking_time;
                    min_thinking_time = max_thinking_time;
                    max_thinking_time = temp;
                }
            } else {
                printf(ERROR_ARGUMENTS_MESSAGE);
                exit(EXIT_FAILURE);
            }
            break;
        case 7:
            if (strcmp(argv[1], "-et") == 0 && strcmp(argv[4], "-tt") == 0) {
                min_eating_time = atoi(argv[2]);
                max_eating_time = atoi(argv[3]);
                if (min_eating_time > max_eating_time) {
                    temp = min_eating_time;
                    min_eating_time = max_eating_time;
                    max_eating_time = temp;
                }
                min_thinking_time = atoi(argv[5]);
                max_thinking_time = atoi(argv[6]);
                if (min_eating_time > max_eating_time) {
                    temp = min_thinking_time;
                    min_thinking_time = max_thinking_time;
                    max_thinking_time = temp;
                }
            } else if (strcmp(argv[1], "-tt") == 0 && strcmp(argv[4], "-et") == 0) {
                min_thinking_time = atoi(argv[2]);
                max_thinking_time = atoi(argv[3]);
                if (min_eating_time > max_eating_time) {
                    temp = min_thinking_time;
                    min_thinking_time = max_thinking_time;
                    max_thinking_time = temp;
                }
                min_eating_time = atoi(argv[5]);
                max_eating_time = atoi(argv[6]);
                if (min_eating_time > max_eating_time) {
                    temp = min_eating_time;
                    min_eating_time = max_eating_time;
                    max_eating_time = temp;
                }
            } else {
                printf(ERROR_ARGUMENTS_MESSAGE);
                exit(EXIT_FAILURE);
            }
            break;
        default:
            printf(ERROR_ARGUMENTS_MESSAGE);
            exit(EXIT_FAILURE);
    }
}

#pragma clang diagnostic pop