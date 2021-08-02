/*
 * Problem-4: Print n times the every third element of the fibonacci series
 * Ayush Singh 1910990059 01/08/21
 * Assignment_5 -> Recursion
*/

#include <stdio.h>

void fib(int n){
    int i;
    int arr[n+1];   //array to memorize the fibonacci series
    arr[0] = 0;
    arr[1] = 1;

    //calculate ith element by adding prev 2 elements
    for(i = 2; i <= 3 * n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    //print the required elements
    printf("n = %d: ", n);
    for(i = 3; i <= 3*n; i += 3)
        printf("%d ", arr[i]);
}

int main(){
    int n = 3;

    fib(n);

    return 0;
}
