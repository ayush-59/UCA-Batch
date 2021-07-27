/*
 * Problem: Bubble sort run time analysis
 * Ayush Singh 1910990059 26/07/21
 * Assignment_2 -> Day2_Coding_Assignment
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>     //functions: gettimeofday()
#include <stdbool.h>      //for using bool

#define RAND 0
#define ASC 1
#define DESC 2

//function to generate array with given size with asc, desc, or random data
void generate_array(int *arr, int size, int mode){
  int i;

  switch(mode){
    case RAND:
    for(i = 0; i < size; i++){
      arr[i] = rand() % size;
    }
    break;
    case ASC:
    for(i = 0; i < size; i++){
      arr[i] = i;
    }
    break;
    case DESC:
    for(i = 0; i < size; i++){
      arr[i] = size - 1 - i;
    }
    break;
  }

}

//function to swap 2 elements of array
void swap(int *arr, int a, int b){
  int temp;
  temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

void bubble_sort(int *arr, int size){
  int i, j;
  bool swapped;

  for(i = 0; i< size; i++){
    swapped = false;
    for(j = i; j < size - 1 - i; j++){
      //compare the adjacent elements
      if(arr[j+1] < arr[j]){
        swap(arr, j, j+1);
        swapped = true;
      }
    }
    if(swapped == false)
      break;
  }
}

//function that calculates time taken to sort arr using bubble sort
long long calc_time(int *arr, int size, int mode){
  struct timeval current_time;

  generate_array(arr, size, mode);
  //get initial Time
  gettimeofday(&current_time, NULL);
  long long start_time = current_time.tv_sec * 1000LL + current_time.tv_usec / 1000;

  bubble_sort(arr, size);

  //get final Time
  gettimeofday(&current_time, NULL);
  long long end_time = current_time.tv_sec * 1000LL + current_time.tv_usec / 1000;

  return end_time - start_time;

}

int main(){
  int size, mode, init_arr_size = 8000, increment = 4000, limit = 36000;

  printf("Time taken by Bubble Sort:\n");
  for(size = init_arr_size; size <= limit; size += increment){
    int *arr = (int *)calloc(size, sizeof(int));

    printf("Size of Array: %d\n",size);
    for(mode = 0; mode < 3; mode++){
      long long time = calc_time(arr, size, mode);

      switch(mode){
          case RAND:
          printf("RAND : ");
          break;
          case ASC:
          printf("ASC : ");
          break;
          case DESC:
          printf("DESC : ");
          break;

      }
      printf("%lld sec\n", time);
    }

  }

  return 0;
}
