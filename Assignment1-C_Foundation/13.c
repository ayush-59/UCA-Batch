/*
 * Problem-13: Write the function strend( char* s , char* t ) which returns
   1 if the string t occurs at end of string s, and zero otherwise
 * Ayush Singh 1910990059 25/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <string.h>   //functions: strlen()


int strend(char *str1, char *str2){
  int i, j, len1, len2;

  len1 = strlen(str1);
  len2 = strlen(str2);

  for(i = 0, j = len1 - len2; i < len2; i++, j++){
    if(str1[j] != str2[i])
        return 0;
  }
  return 1;
}

int main(){
  char str1[25], str2[25];

  printf("Enter first string: ");
  scanf("%s", str1);
  printf("Enter second string: ");
  scanf("%s", str2);

  printf("%d", strend(str1, str2));

  return 0;
}
