/*
 * Problem-2: Bit Xor
 * Ayush Singh 1910990059 03/08/21
 * Assignment_3 -> Bits and Bytes
*/

/*
*  bitXor - x ^ y using only ~ and &
* Example bitXor(4, 5) = 1
* Legal ops:  ~ &
*Max ops: 14
*/
#include <stdio.h>

int bitXor (int a, int b) {
    return ~(~(a&~b) & ~(~a&b));
}

int main()
{
    int a = 4, b = 5;
    int result;
    result = bitXor(a, b);
    printf("%d",result);

    return 0;
}
