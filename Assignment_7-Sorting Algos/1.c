/*
 * Problem-1: Inversion Count for an Array
 * Ayush Singh 1910990059 12/08/21
 * Assignment_7 -> Sorting Algos
*/

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int start, int end, int *count){

    if(start == end){
        return;
    }

    int mid =  start + (end-start) / 2;

    mergeSort(arr, start, mid, count);
    mergeSort(arr, mid + 1, end, count);

    int i, j, k = start;


    int n1 = mid - start + 1, n2 = end - mid;
    int Left[n1], Right[n2];

    // putting left elements in Left[] Array
    for(i = 0; i < n1; i++){
        Left[i] = arr[start + i];
    }
    // putting right elements in Right[] Array
    for(i = 0; i < n1; i++){
        Right[i] = arr[mid + 1 + i];
    }

    // Merging Left and Right arrays into original array
    for(i = 0, j = 0; i < n1 && j < n2; ){
        if(Left[i] <= Right[j]){
            arr[k++] = Left[i++];
        }
        else{
            arr[k++] = Right[j++];
            *count += n1 - i;       //updating the inversion count
        }
    }
    while(i < n1){
        arr[k++] = Left[i++];
    }
    while(j < n2){
        arr[k++] = Right[j++];
    }


}

int main()
{
    int n, count = 0;


    printf("Enter size of arr: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter Elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d ", &arr[i]);

    mergeSort(arr, 0, n-1, &count);

    printf("\nInversion count = %d",count);

    return 0;
}
