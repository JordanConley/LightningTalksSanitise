/*
 * BUFFER OVERRUN EXAMPLE
 */

#include <stdio.h>

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    int i;
    int buff[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (i = 1; i <= 10; i++) {
        printf("%d: %d\n", i, buff[i]);
    }

    return 0;
}

