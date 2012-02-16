#include <string.h>

const unsigned int MAXD = (unsigned int) -1;

typedef struct bigint {
    unsigned int size;
    int *n;
} bigint;

bigint *bi_create(int);

void bi_delete(bigint *);

bigint *bi_add(bigint *, bigint *);

bigint *bi_sub(bigint *, bigint *);
