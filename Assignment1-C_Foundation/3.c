/*
 * Problem-3: Program to count vowels and consonants in given string
 * Ayush Singh 1910990059 24/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <ctype.h>    //functions: tolower(), isalpha()

//function to count vowels and consonant and display result
void count(char *str){
  int i, vowels_count = 0, consonants_count = 0;
  char letter;

  for(i = 0; str[i] != '\0'; i++){
    //if character is not alphabet then continue
    if(!isalpha(str[i]))
      continue;

    letter = tolower(str[i]);

    //checking for vowel
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' )
      vowels_count++;
    else
      consonants_count++;
  }
  printf("vowels = %d\nconsonants = %d", vowels_count, consonants_count);
}

int main(){
  int len;

  printf("Enter length of string: ");
  scanf("%d", &len);

  char str[len];

  printf("Enter String: ");
  scanf("%s", str);

  //calling count function
  count(str);

  return 0;
}
