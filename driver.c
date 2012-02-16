#include <stdio.h>
#include "bigint.h"

int main(int argc, char *argv[]) {
    bigint *a, *b, *c;

    // test 1
    a = bi_createfromint(32);
    b = bi_createfromint(32);
    bi_print(a);
    printf(" cmp ");
    bi_print(b);
    printf(" is %d\n", bi_cmp(a, b));
    bi_delete(a);
    bi_delete(b);

    // test 2
    a = bi_createfromint(32);
    b = bi_createfromint(31);
    bi_print(a);
    printf(" cmp ");
    bi_print(b);
    printf(" is %d\n", bi_cmp(a, b));
    bi_delete(a);
    bi_delete(b);

    // test 3
    a = bi_createfromint(32);
    b = bi_createfromint(39);
    bi_print(a);
    printf(" cmp ");
    bi_print(b);
    printf(" is %d\n", bi_cmp(a, b));
    bi_delete(a);
    bi_delete(b);

    // test 4
    a = bi_createfromint(MAXD + 10);
    b = bi_createfromint(MAXD + 5);
    bi_print(a);
    printf(" cmp ");
    bi_print(b);
    printf(" is %d\n", bi_cmp(a, b));
    bi_delete(a);
    bi_delete(b);

    // test 5
    a = bi_createfromint(10);
    b = bi_createfromint(MAXD + 5);
    bi_print(a);
    printf(" cmp ");
    bi_print(b);
    printf(" is %d\n", bi_cmp(a, b));
    bi_delete(a);
    bi_delete(b);

    // test 6
    a = bi_createfromint(32);
    b = bi_createfromint(39);
    bi_print(a);
    printf(" + ");
    bi_print(b);
    printf(" is ");
    c = bi_add(a, b);
    bi_print(c);
    printf("\n");
    bi_delete(a);
    bi_delete(b);
    bi_delete(c);

    // test 7
    a = bi_createfromint(5);
    b = bi_createfromint(MAXD);
    bi_print(a);
    printf(" + ");
    bi_print(b);
    printf(" is ");
    c = bi_add(a, b);
    bi_print(c);
    printf("\n");
    bi_delete(a);
    bi_delete(b);
    bi_delete(c);

    // test 8
    a = bi_createfromint(MAXD);
    b = bi_createfromint(MAXD + 5);
    bi_print(a);
    printf(" + ");
    bi_print(b);
    printf(" is ");
    c = bi_add(a, b);
    bi_print(c);
    printf("\n");
    bi_delete(a);
    bi_delete(b);
    bi_delete(c);

    // test 8
    a = bi_createfromint(MAXD);
    b = bi_createfromint(5);
    bi_print(a);
    printf(" - ");
    bi_print(b);
    printf(" is ");
    c = bi_sub(a, b);
    bi_print(c);
    printf("\n");
    bi_delete(a);
    bi_delete(b);
    bi_delete(c);

    // test 9
    a = bi_createfromint(MAXD);
    b = bi_createfromint(5);
    bi_print(a);
    printf(" * ");
    bi_print(b);
    printf(" is ");
    c = bi_mult(a, b);
    bi_print(c);
    printf("\n");
    bi_delete(a);
    bi_delete(b);
    bi_delete(c);

     // test 10
    a = bi_createfromint(MAXD);
    b = bi_createfromint(MAXD);
    bi_print(a);
    printf(" * ");
    bi_print(b);
    printf(" is ");
    c = bi_mult(a, b);
    bi_print(c);
    printf("\n");
    bi_delete(a);
    bi_delete(b);
    bi_delete(c);

    return 0;
}
