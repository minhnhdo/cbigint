#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern const int MAXD;

typedef struct bigint bigint;

bigint *bi_create(int);
bigint *bi_createfromint(int);
void bi_delete(bigint *);
void bi_print(bigint *);
bigint *bi_add(bigint *, bigint *);
bigint *bi_sub(bigint *, bigint *);
bigint *bi_mult(bigint *, bigint *);
