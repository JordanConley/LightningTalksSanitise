/* 
 * RACE CONDITION EXAMPLE 1
 */

#include <stdio.h>

#include <pthread.h>

volatile int counter = 0;
volatile int go = 0;

void* work(void* data) {

    char* id = data;

    while (!go) {
    }
    
    while (counter < 100) {
        counter++;

        printf("%s: %d\n", id, counter);
    }

    pthread_exit(NULL);
    return data;
}

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    counter = 0;

    pthread_t a, b;

    pthread_create(&a, NULL, work, "a");
    pthread_create(&b, NULL, work, "b");

    for (volatile int i = 0; i < 100000; i++) {
        printf("waiting\n");
    }
    go = 1;

    pthread_exit(NULL);

    return 0;
}

