/*
 * Problem-6: Conditional
 * Ayush Singh 1910990059 16/08/21
 * Assignment_3 -> Bits and Bytes
*/

/*
* conditional - same as x ? y : z
* example conditional (2, 4, 5) = 4
* ! ~ & ^ | + << >>
* Max ops: 16
*/

#include <stdio.h>

int conditional(int x, int y, int z) {
    x = ~!!x + 1;
    return (x & y) | (~x & z);
}

int main()
{   int res, x = 0, y = 4, z = 5;
    res = conditional(x, y, z);
    printf("%d", res);

    return 0;
}
