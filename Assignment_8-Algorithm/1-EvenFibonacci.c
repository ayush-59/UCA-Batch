/*
 * Problem-1: Print n numbers in Fibonacci series that are even. 
 * Ayush Singh 1910990059 15/08/21
 * Assignment_8 -> Algorithm
*/

#include <stdio.h>

void fib(int n){
    int i, dp[n];
    dp[0] = 2;
    dp[1] = 8;

    for(i = 2; i < n; i++){
        dp[i] = 4*dp[i-1] + dp[i-2];
    }
    for(i = 0; i < n; i++){
        printf("%d ",dp[i]);
    }
}

int main()
{   int n = 5;
    fib(n);

    return 0;
}
