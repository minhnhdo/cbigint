#include "bigint.h"

const unsigned int MAXD = (unsigned int) -1;

struct bigint {
    int size;
    int *n;
};

bigint *bi_create(int size) {
    if (size <= 0)
        return NULL;
    bigint *retval = malloc(sizeof(bigint));
    if (retval == NULL)
        return NULL;
    retval->size = size;
    retval->n = malloc(size*sizeof(unsigned int));
    if (retval->n == NULL) {
        free(retval);
        return NULL;
    }
    memset(retval->n, 0, size*sizeof(unsigned int));
    return retval;
}

void bi_delete(bigint *a) {
    free(a->n);
    free(a);
}

int bi_cmp(bigint *a, bigint *b) {
    int *arr[2] = {a->n, b->n};
    int bigger = (a->size > b->size) ? a->size : b->size;
    int which = (a->size > b->size) ? 0 : 1;
    int i;
    for (i = 0; i < a->size && i < b->size; i++) {
        if (a->n[i] != b->n[i])
            return a->n[i] - b->n[i];
    }
    for (; i < bigger; i++) {
        if (arr[which][i] != 0)
            return (which == 0) ? 1 : -1;
    }
    return 0;
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
    for (i = 0; i < sa && i < sb; i++) {
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

bigint *bi_mult(bigint *a, bigint *b) {
    bigint *retval = bi_create(a->size + b->size);
    if (retval == NULL)
        return NULL;
}

bigint *bi_sub(bigint *a, bigint *b) {
    ASSERT(bi_cmp(a, b) >= 0);
}
