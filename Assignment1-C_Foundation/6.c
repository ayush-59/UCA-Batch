/*
 * Problem-6: Program to check given string is palindrome or not, considering only
   alphanumeric characters and ignoring cases
 * Ayush Singh 1910990059 24/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <ctype.h>    //functions: tolower(), isalpha()
#include <string.h>   //functions: strlen()

//function to check palindrome
int check_palindrome(char *str){
  int left, right;
  char l_char, r_char;

  left = 0;
  right = strlen(str);

  while(left < right){
    l_char = tolower(str[left]);
    r_char = tolower(str[right]);

    //if the character is not alphanumeric then go to next character
    if(!isalpha(l_char)){
      left++;
      continue;
    }else if(!isalpha(r_char)){
      right--;
      continue;
    }

    if(l_char != r_char)
      return 0;

    left++;
    right--;
  }
  return 1;
}

int main(){
  char str[25];

  printf("Enter String: ");
  fgets(str, 25, stdin);

  int result = check_palindrome(str);
  if(result == 1)
    printf("Palindrome");
  else
    printf("Not Palindrome");

  return 0;
}
