#include <bigint.h>

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
    memset(retval->n, 0, size*sizeof(unsigned int));
    return retval;
}

void bi_delete(bigint *a) {
    free(a->n);
    free(a);
}

void bi_printnum(bigint *a) {
}

bigint *bi_add(bigint *a, bigint *b) {
    int sa = a->size,
        sb = b->size,
        bigger = (sa < sb) ? sb : sa;
    int which = (sa < sb) ? 1 : 0;
    int *na = a->n,
        *nb = b->n;
    int *arr[2] = {na, nb};
    bigint *retval = bi_create(bigger + 1);
    if (retval == NULL)
        return NULL;
    int *n = retval->n;
    long long carry = 0;
    long long tmp = 0;
    int i;
    // whole number adding
        // per "digit" adding
    for (i = 0; i < bigger; i++) {
        tmp = na[i] + nb[i] + carry;
        if (tmp > MAXD) {
            n[i] = MAXD;
            carry = tmp - MAXD;
        }
        else {
            n[i] = tmp;
            carry = 0;
        }
    }
    while (carry != 0 && i < bigger) {
        tmp = arr[which][i] + carry;
        if (tmp > MAXD) {
            carry = tmp - MAXD;
            n[i] = MAXD;
        }
        else {
            n[i] = tmp;
            carry = 0;
        }
    }
    return retval;
}

bigint *bi_sub(bigint *a, bigint *b) {
}
