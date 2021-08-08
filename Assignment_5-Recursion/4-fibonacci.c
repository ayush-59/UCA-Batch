/*
 * Problem-4: Print n times the every third element of the fibonacci series
 * Ayush Singh 1910990059 01/08/21
 * Assignment_5 -> Recursion
*/

#include <stdio.h>

void fib(int n){
    int i;
    int arr[n+1];   //array to memorize the fibonacci series
    arr[0] = 2;
    arr[1] = 8;

    //calculate ith element by using modified formula
    for(i = 2; i < n; i++){
        arr[i] = 4*arr[i-1] + arr[i-2];
    }

    //print the required elements
    printf("n = %d: ", n);
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(){
    int n = 5;

    fib(n);

    return 0;
}
