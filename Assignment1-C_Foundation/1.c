/*
 * Problem-1: Program to awap 2 variable without using third variable
 * Ayush Singh 1910990059 24/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>

void swap(int *a, int *b){
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

int main(){
  int a = 10, b = 20;
  swap(&a, &b);
  printf("a = %d\nb = %d",a , b);
}
