/*
 * RACE CONDITION EXAMPLE 2
 */

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

struct td {
    FILE* s;
    char* name;
};

/*
 * worker thread
 */
void* work(void* data) { 
    struct td* d = data;

    /* get 10 characters from data->s and print them out to stdout */
    for (int i = 0; i < 10; i++) {
        int c = fgetc(d->s);

        if (c == EOF) {
            break;
        } else {
            printf("%s: %c\n", d->name, (char) c);
        }
    }

    pthread_exit(NULL);
    return data;
}

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    pthread_t a, b;

    /* initialise data for worker a */
    struct td* a_data = malloc(sizeof(*a_data));
    a_data->s = stdin;
    a_data->name = "Thread A";

    /* initialise data for worker b */
    struct td* b_data = malloc(sizeof(*b_data));
    b_data->s = stdin;
    b_data->name = "Thread B";
    
    /* create workers */
    pthread_create(&a, NULL, work, a_data);
    pthread_create(&b, NULL, work, b_data);

    /* wait for workers to finish */
    pthread_join(a, NULL);
    pthread_join(b, NULL);

    return 0;
}

