/*
 * DEREFERENCE BAD POINTER
 */

#include <stdio.h>
#include <stdlib.h>

struct big_struct {
    char* a;
    char* b;
};

int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    struct big_struct sa;
    sa.a = "fish";
    sa.b = NULL;

    printf("%s\n", sa.b);

    return 0;
}

