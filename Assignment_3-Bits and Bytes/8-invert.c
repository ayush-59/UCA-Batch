/*
 * Problem-8: Invert
 * Ayush Singh 1910990059 16/08/21
 * Assignment_3 -> Bits and Bytes
*/

/*
* Return x with the n bits that begin at position p inverted (i.e. turn 0
* into 1 and vice versa)
* and the rest left unchanged. Consider the indices of x to begin with the
* lower -order bit   numbered
* Legal ops: ~ & ^ | << >>
* as zero
*/

#include <stdio.h>

int invert (int x, int p, int n) {
    int mask;
    mask = ~(~0<<n)<<p;
    return mask^x;

}

int main()
{   int res, x = 23, p = 3, n = 2;
    res = invert(x, p, n);
    printf("%d ",res);


    return 0;
}
