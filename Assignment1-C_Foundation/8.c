/*
 * Problem-4: Program to reverse a character string
 * Ayush Singh 1910990059 25/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <string.h>   //functions: strlen()

//function to reverse string
void reverse(char *str){
  int i, temp, len;
  len = strlen(str);

  for(i = 0; i < len/2; i++){
    //swapping the (i)th and (size-i-1)th element
    temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

}

int main(){
  char str[25];

  printf("Enter string: ");
  fgets(str, 25, stdin);

  reverse(str);

  printf("\nReverse String: %s", str);

}
