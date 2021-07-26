/*
 * Problem-12: Write the function strrindex( char* s , char* t ) which returns
   the position of the rightmost occurrence of t in s , or - 1 if there is none
 * Ayush Singh 1910990059 25/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <string.h>   //functions: strlen()


int strrindex(char *str1, char *str2){
  int i, j, len1, len2;
  char c;
  len1 = strlen(str1);
  len2 = strlen(str2);

  for(i = 0; i < len2; i++){
    c = str2[i];
    for(j = len1 - 1; j >= 0; j--){
      if(str1[j] == c)
        return j;
    }
  }
  return -1;
}

int main(){
  char str1[25], str2[25];

  printf("Enter first string: ");
  scanf("%s", str1);
  printf("Enter second string: ");
  scanf("%s", str2);

  printf("%d", strrindex(str1, str2));

  return 0;
}
