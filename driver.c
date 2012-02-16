#include <stdio.h>
#include "bigint.h"

int main(int argc, char *argv[]) {
    bigint *a, *b;
    a = bi_create(32);
    b = bi_create(32);
    printf("%d\n", bi_cmp(a, b));
    bi_delete(a);
    bi_delete(b);
    return 0;
}
