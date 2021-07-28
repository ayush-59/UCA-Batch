/*
 * Problem-14: Write the versions of the library functions strncpy, strncat,
   and strncmp, which operate on at most the first n characters of their
   argument strings
 * Ayush Singh 1910990059 27/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <string.h>   //functions: strlen()

//function to compare first n characters of two strings
int strncmp(char *s, char *t, int n){  //n- no. of characters to compare
  int i;

  for(i = 0; i < n; i++){
    if(s[i] != t[i])
        return s[i] - t[i];
  }
  return 0;
}

//function to copy first n characters of string t to string s
void strncpy(char *s, char *t, int n){  //n- no. of characters to copy
  int i;

  for(i = 0; i < n; i++){
    s[i] = t[i];
  }
  s[i] = '\0';
}

//function to concatenate n characters of string t to string s
void strncat(char *s, char *t, int n){  //n- no. of characters to concatenate
  int i,len_s;
  len_s = strlen(s);

  for(i = 0; i < n; i++){
    s[len_s + i] = t[i];
  }
  s[len_s + i] = '\0';
}

int main(){
  char str1[25], str2[25];
  int n;

  printf("Enter first string: ");
  scanf("%s", str1);
  printf("Enter second string: ");
  scanf("%s", str2);
  printf("Enter value of n: ");
  scanf("%d", &n);


  return 0;
}
