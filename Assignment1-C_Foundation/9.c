/*
 * Problem-9: Program to convert Hexadecimal number to decimal
 * Ayush Singh 1910990059 25/07/21
 * Assignment_1 -> C Foundation
*/


#include <stdio.h>
#include <string.h>   //functions: strlen()

int conv(char c){
  if(c >=48 && c < 58)
    return c - 48;
  else if(c >= 65 && c <= 71)
    return c-65 + 10;
  else if(c >= 97 && c <= 103)
    return c-97 + 10;
  else
    return -1;
}

int htoi(char *str){
    int i, len, decimal = 0, x, base = 1;
    len = strlen(str);

    for(i = --len; i >= 0; i--){
      x = conv(str[i]);
      if(x == -1)
        return -1;
      decimal += x * base;
      base *= 16;
    }
    return decimal;
}

int main(){
  char str[25];
  int result;

  printf("Enter Hexadecimal No: ");
  fgets(str, 25, stdin);

  result = htoi(str+2);
  if(result == -1)
    printf("Invalid Input");
  else
    printf("No. in Decimal: %d", result);
  return 0;
}
