/*
 * Problem-2: Selection sort using Recursion
 * Ayush Singh 1910990059 02/08/21
 * Assignment_5 -> Recursion
*/

#include <stdio.h>

//function to swap 2 items in array using index
//a,b - index
void swap(int *arr, int a, int b){
  int temp;
  temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

//function to select the min element in array and return its index
int get_min_index(int *arr, int size){
  int i, min_index;

  min_index = 0;
  for(i = 0; i < size; i++){
    if(arr[i] < arr[min_index])
      min_index = i;
  }
  return min_index;
}

void selection_sort(int *arr, int size){
  int min_index;

  if(size == 1)
    return;

  //get index of min element
  min_index = get_min_index(arr, size);

  //if min element is not at start then swap it with first element
  if(min_index != 0)
    swap(arr, 0, min_index);

  //first element is sorted
  //now sort next (size-1) elements
  selection_sort(arr + 1, size - 1);
}

int main(){
  int arr[] = {6,3,1,7,4};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Before Sorting : ");
  for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");

  selection_sort(arr, size);

  printf("After Sorting  : ");
  for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  return 0;
}
