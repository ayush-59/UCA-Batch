/*
 * Problem-2: Program to print a pyramid with given number of steps
               #
              # #
            #  #  #
          #  #  #  #
 * Ayush Singh 1910990059 24/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>

void pyramid(int n){
  int i, j;

  for(i = 1; i <= n; i++){
    //loop for printing spaces before pattern
    for(j = i; j < n; j++)
      printf(" ");

    //loop to print pattern
    for(j = 1; j <= i; j++){
      printf("#");
      if(j != i)
        printf(" ");
    }
    printf("\n");
  }
}

int main(){
  int n;

  printf("Enter size of pyramid ");
  scanf("%d", &n);
  pyramid(n);

  return 0;
}
