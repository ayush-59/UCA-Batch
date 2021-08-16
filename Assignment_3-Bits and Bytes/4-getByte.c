/*
 * Problem-4: Get Byte
 * Ayush Singh 1910990059 15/08/21
 * Assignment_3 -> Bits and Bytes
*/

/*
* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
*Legal ops: ! ~ & ^| + << >>
Max ops: 6
*/
#include <stdio.h>

int getByte(int x, int n) {
    return (x >> 8*n) & 0xff;
}


int main()
{   int res, n=2, x=0x12345678;
    res = getByte(x, n);
    printf("%x", res);

    return 0;
}
