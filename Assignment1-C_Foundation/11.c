/*
 * Problem-11: Write the function any( char* s1 , char* s2), which returns the first location
   in the string1 where any character from the string2 occurs, or  -1 if s1 contains no
   characters from s2
 * Ayush Singh 1910990059 25/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <string.h>   //functions: strlen()


int any(char *str1, char *str2){
  int i, j, len1, len2;
  char c;
  len1 = strlen(str1);
  len2 = strlen(str2);

  for(i = 0; i < len2; i++){
    c = str2[i];
    for(j = 0; j < len1; j++){
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

  printf("%d", any(str1, str2));

  return 0;
}
