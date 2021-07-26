/*
 * Problem-5: Program to multiply 2 matrixes
 * Ayush Singh 1910990059 24/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include<stdlib.h>

//function to multiply two matrixes
int **multiply_matrix(int row1, int col1, int matrix1[][col1], int row2, int col2, int matrix2[][col2]){
  int i, j, k;
  int **new_matrix = (int **)calloc(row1, sizeof(int *));

  for(i = 0; i < row1; i++){
    new_matrix[i] = (int *)calloc(col2, sizeof(int));
    for(j = 0; j < col2; j++){
      new_matrix[i][j] = 0;

      for(k = 0; k < col1; k++){
        new_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return new_matrix;
}

int main(){
  int row, col, row1, col1, row2, col2;

  printf("Enter dimensions of first matrix: ");
  scanf("%d %d", &row1, &col1);

  printf("Enter dimensions of second matrix: ");
  scanf("%d %d", &row2, &col2);

  if(col1 != row2){
    printf("Invalid input");
    return 0;
  }

  int matrix1[row1][col1], matrix2[row2][col2];

  printf("Enter first matrix: ");
  for(row = 0; row < row1; row++){
    for(col = 0; col < col1; col++){
      scanf("%d ", &matrix1[row][col] );
    }
  }
  printf("Enter second matrix: ");
  for(row = 0; row < row2; row++){
    for(col = 0; col < col2; col++){
      scanf("%d ", &matrix2[row][col] );
    }
  }

  //calling count function
  int **new_matrix = multiply_matrix(row1, col1, matrix1, row2, col2, matrix2);

  printf("New matrix:\n");
  for(row = 0; row < row1; row++){
    for(col = 0; col < col2; col++){
      printf("%d ",new_matrix[row][col] );
    }
    printf("\n");
  }

  return 0;
}
