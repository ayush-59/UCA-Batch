/*
 * Problem-7: Program to print all input lines that are longer than 80 characters
 * Ayush Singh 1910990059 25/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>   //functions: strlen()

int main(){
  int max_line_length = 256;
  char *line_buffer = (char *)calloc(max_line_length, sizeof(char));

  //open the file in read mode
  FILE *file = fopen("file.txt", "r");
  if(!file){
    printf("File not Found");
    return 0;
  }

  while(!feof(file)){
    //fetch data of file line by line
    fgets(line_buffer, max_line_length, file);
    if(strlen(line_buffer) >= 80)
      printf("%s", line_buffer);
  }

  //close the file
  fclose(file);
  return 0;
}
