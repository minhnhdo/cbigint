#include <stdlib.h>
#include <string.h>

extern const unsigned int MAXD;

typedef struct bigint bigint;

bigint *bi_create(int);
void bi_delete(bigint *);
bigint *bi_add(bigint *, bigint *);
bigint *bi_sub(bigint *, bigint *);
