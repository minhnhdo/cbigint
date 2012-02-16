#include <stdio.h>

typedef struct bigint {
    unsigned int size;
    int *n;
} bigint;

const unsigned int MAXD = (unsigned int) -1

void bi_delete(bigint *a) {
    free(a->n);
    free(a);
}

bigint *bi_create(int size) {
    if (size <= 0)
        return NULL;
    bigint *retval = malloc(sizeof(bigint));
    if (retval == NULL)
        return NULL;
    retval->size = size;
    retval->n = malloc(size*sizeof(unsigned int));
    if (retval->n == NULL)
        return NULL;
    return retval;
}

bigint *bi_add(bigint *a, bigint *b) {
    int sa = a->size,
        sb = b->size;
    int *na = a->n,
        *nb = b->n;
    bigint *retval = bi_create(((sa < sb) ? sb : sa) + 1);
    if (retval == NULL)
        return NULL;
    int *n = retval->n;
    int carry = 0;
    // whole number adding
        // per "digit" adding
    for (int i = 0; i < sa && i < sb; i++) {
        if (carry == 1 && na[i] > MAXD - nb[i] + 1) {
            n[i] = MAXD;
            carry = 1;
        }
        else if (carry == 1 && na[i] <= MAXD - nb[i] + 1) {
        }
        else
            n[i] = 
    }
}

bigint *bi_sub(bigint *a, bigint *b) {
}

int main(int argc, char *argv[]) {
    return 0;
}
