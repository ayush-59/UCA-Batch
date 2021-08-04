/*
*  bitAnd - x & y using only ~ and |
* Example bitAnd(6, 5) = 4
* Legal ops:  ~ |
* Max ops: 8
*/
#include <stdio.h>

int bitAnd (int a, int b){
     return ~(~a | ~b);
}

int main()
{
    int a = 6, b = 5;
    int result;
    result = bitAnd(a, b);
    printf("%d",result);

    return 0;
}
