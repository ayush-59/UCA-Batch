/*
 * Problem-2: Print mth smallest number from unsorted array.
 * Ayush Singh 1910990059 16/08/21
 * Assignment_8 -> Algorithm
*/

#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int start, int end){
    int i, j, pivot;
    pivot = arr[end];
    i = start;
    for(j = start; j < end; j++){
        if(arr[j] < pivot){
            if(i != j)
                swap(arr + i, arr + j);
            i++;
        }
    }
    swap(arr +i, arr +end);
    return i;
}

int MthSmallest(int *arr, int start, int end, int m){

    int p = partition(arr, start, end);
    if(p == m-1)
        return arr[p];
    else if(p > m-1)
        MthSmallest(arr, start, p-1, m);
    else
        MthSmallest(arr, p+1, end, m);
}

int main()
{
    int m, n, res;
    int arr[] = {6,2,3,8,1,9,4,0,5,7};
    n = sizeof(arr) / sizeof(*arr);
    m = 8;

    if(m >= n){
      printf("Invalid Input");
      return 0;
    }
    
    res = MthSmallest(arr, 0, n-1, m);

    printf("%d", res);
    return 0;
}
