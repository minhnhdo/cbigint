#include "bigint.h"

const int MAXD = 1000000000;

struct bigint {
    int size;
    int *n;
};

bigint *bi_create(int dplace) {
    int size = dplace / 9 + ((dplace % 9 != 0) ? 1 : 0);
    if (size <= 0)
        return NULL;
    bigint *retval = malloc(sizeof(bigint));
    if (retval == NULL)
        return NULL;
    retval->size = size;
    retval->n = malloc(size*sizeof(int));
    if (retval->n == NULL) {
        free(retval);
        return NULL;
    }
    memset(retval->n, 0, size*sizeof(int));
    return retval;
}

bigint *bi_createfromint(int n) {
    bigint *retval = bi_create(10);
    if (retval == NULL)
        return NULL;
    if (n >= MAXD) {
        retval->n[0] = n % MAXD;
        retval->n[1] = n / MAXD;
    }
    else
        retval->n[0] = n;
    return retval;
}

void bi_delete(bigint *a) {
    free(a->n);
    free(a);
}

void bi_print(bigint *a) {
    int *n = a->n;
    int printed = 0;
    int i;
    // printf("a->size=%d\n", a->size);
    for (i = a->size - 1; i >= 0; i--) {
        if (n[i] != 0) {
            if (!printed)
                printf("%d", n[i]);
            else
                printf("%09d", n[i]);
            printed = 1;
        }
        else if (printed) {
            printf("%09d", 0);
        }
    }
    if (!printed)
        printf("0");
}

int bi_cmp(bigint *a, bigint *b) {
    if (a->size < b->size)
        return bi_cmp(b, a);
    int i;
    int retval = 0;
    for (i = 0; i < b->size; i++) {
        if (a->n[i] != b->n[i]) {
            retval = a->n[i] - b->n[i];
        }
    }
    if (retval > 0)
        return 1;
    for (; i < a->size; i++) {
        if (a->n[i] != 0)
            return 1;
    }
    return retval;
}

bigint *bi_add(bigint *a, bigint *b) {
    if (a->size < b->size)
        return bi_add(b, a);
    int sa = a->size,
        sb = b->size;
    int *na = a->n,
        *nb = b->n;
    bigint *retval = bi_create(sa*9 + 1);
    if (retval == NULL)
        return NULL;
    int *n = retval->n;
    int carry = 0;
    int tmp = 0;
    int i;
    // whole number adding
        // per "digit" adding
    for (i = 0; i < sb; i++) {
        tmp = na[i] + nb[i] + carry;
        n[i] = tmp % MAXD;
        carry = tmp / MAXD;
        // printf("carry = %d, n[%d]=%d\n", carry, i, n[i]);
    }
    while (carry != 0 && i < sa) {
        tmp = na[i] + carry;
        n[i] = tmp % MAXD;
        carry = tmp / MAXD;
        i++;
    }
    return retval;
}

bigint *bi_sub(bigint *a, bigint *b) {
    if (bi_cmp(a, b) < 0)
        return bi_create(1);
    int sa = a->size,
        sb = b->size;
    int *na = a->n,
        *nb = b->n;
    bigint *retval = bi_create((sa < sb) ? sb : sa);
    if (retval == NULL)
        return NULL;
    int *n = retval->n;
    int biggersize = retval->size;
    int *bigger = ((sa > sb) > 0) ? na : nb;
    int tmp = 0,
        carry = 0;
    int i;
    for (i = 0; i < sa && i < sb; i++) {
        if (na[i] < nb[i] + carry) {
            n[i] = MAXD + na[i] - nb[i] - carry;
            carry = 1;
        }
        else {
            n[i] = na[i] - nb[i] - carry;
            carry = 0;
        }
        /* printf("na[%d]=%d\n", i, na[i]);
        printf("nb[%d]=%d\n", i, nb[i]);
        printf("n[%d]=%d\n", i, n[i]);*/
    }
    while (carry != 0 && i < biggersize) {
        if (bigger[i] < carry)
            n[i] = MAXD - 1;
        else {
            n[i] = bigger[i] - carry;
            carry = 0;
        }
        // printf("n[%d]=%d\n", i, n[i]);
        i++;
    }
    return retval;
}

bigint *bi_mult(bigint *a, bigint *b) {
    bigint *retval = bi_create(a->size + b->size);
    if (retval == NULL)
        return NULL;
}
