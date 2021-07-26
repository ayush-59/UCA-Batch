/*
 * Problem-4: Program to reverse an array
 * Ayush Singh 1910990059 24/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>

//function to reverse an array
void reverse(int *arr, int size){
  int i, temp;

  for(i = 0; i < size/2; i++){
    //swapping the (i)th and (size-i-1)th element
    temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }

}

int main(){
  int size, i;

  printf("Enter size of Array: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter Elements of Array: ");
  for(i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  reverse(arr, size);

  printf("\nReverse Array: ");
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);

}
