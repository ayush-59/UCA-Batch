/*
 * Problem-5: Logical Shift
 * Ayush Singh 1910990059 15/08/21
 * Assignment_3 -> Bits and Bytes
*/

/* logicalShift - shift x to the right by n, using a logical shift
*  can assume that 0 <=n<=31
* examples: logicalShift(0x87654321, 4) = 0x8765432
*  Legal ops:  ~ & ^ | + << >>
*Max ops: 20
*/

#include <stdio.h>

int logicalShift(int x, int n) {
    x = x>>1 & 0x7fffffff;
    return (x >> (n-1));
}

int main()
{   int res, n=8, x=0x87654321;
    res = logicalShift(x, n);
    printf("%x", res);

    return 0;
}
