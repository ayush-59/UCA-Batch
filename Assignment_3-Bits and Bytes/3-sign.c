/*
 * Problem-3: Sign
 * Ayush Singh 1910990059 15/08/21
 * Assignment_3 -> Bits and Bytes
*/

/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10
*/

#include <stdio.h>

int sign(int x) {
   return (x>>31) | ~((~x+1)>>31) + 1;
}

int main()
{   int res, n=-56;
    res = sign(n);
    printf("%d is ", n);
    switch(res){
        case 0:
        printf("Zero");
        break;
        case 1:
        printf("Positive");
        break;
        case -1:
        printf("Negative");
        break;
    }

    return 0;
}
