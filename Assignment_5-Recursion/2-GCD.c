/*
 * Problem-2: Find GCD of 2 numbers
 * Ayush Singh 1910990059 02/08/21
 * Assignment_5 -> Recursion
*/

#include <stdio.h>

int gcd(int a, int b){
    //when remainder is 0 then we have found the GCD
    if(b == 0)
      return a;

    return gcd(b, a%b);
}

int main(){
    int a = 5, b = 15, result;
    result = gcd(a, b);
    printf("GCD of %d and %d: %d", a, b, result);

    return 0;
}
