/*
 * Problem-7: Bang
 * Ayush Singh 1910990059 16/08/21
 * Assignment_3 -> Bits and Bytes
*/

/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12
*/

#include <stdio.h>

int bang(int x) {
    return ~(~( (x>>31) + ((~x+1)>>31) ) ) + 1;
}

int main()
{   int res, x = 0;
    res = bang(x);
    printf("%d", res);

    return 0;
}
