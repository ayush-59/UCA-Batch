/*
 * Problem-10: squeeze function that deletes each character in s1 that matches any character in the string s2
 * Ayush Singh 1910990059 25/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <string.h>   //functions: strlen()

int char_in_str(char c, char *str){
  int i, len = strlen(str);

  for(i = 0; i < len; i++){
    if(str[i] == c)
      return 1;
  }
  return 0;
}

void squeeze(char *str1, char *str2){
  int i, k = 0, len1;
  len1 = strlen(str1);

  for(i = 0; i < len1; i++){
    if(!char_in_str(str1[i], str2))
      str1[k++] = str1[i];
  }
  str1[k] = '\0';
}

int main(){
  char str1[25], str2[25];

  printf("Enter first string: ");
  scanf("%s", str1);
  printf("Enter string to squeeze from first string: ");
  scanf("%s", str2);

  squeeze(str1, str2);

  printf("String after squeezing: %s", str1);
  return 0;
}
