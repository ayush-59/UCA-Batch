/*
 * Problem-14: Write the program expr, which evaluates a reverse Polish
   expression from the command line, where each operator or operand is a
   separate argument
 * Ayush Singh 1910990059 27/07/21
 * Assignment_1 -> C Foundation
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Stack {
  double data;
  struct Stack *next;
} *Top = NULL;

struct Stack *create_node(double data){
  struct Stack *node = (struct Stack *)malloc(sizeof(struct Stack));
  node->data = data;
  node->next = NULL;
  return node;
}

void push(double data){
  struct Stack *new_node = create_node(data);

  if(Top == NULL)
    Top = new_node;
  else{
    new_node->next = Top;
    Top = new_node;
  }

}

double pop(){
  if(!Top){
    printf("Underflow!");
    return -1;
  }
  double data = (Top)->data;
  Top = (Top)->next;
  return data;
}

void show(){
  struct Stack *curr = Top;
  while(curr != NULL){
    printf("%lf ", curr->data);
    curr = curr->next;
  }
}

double eval(double a, double b, char ch){
  switch(ch){
    case '+':
    return a + b;
    break;
    case '-':
    return a - b;
    break;
    case '*':
    return a * b;
    break;
    case '/':
    return b / a;
    break;
  }
}

double expr(){
  struct Stack *curr = Top;
  int i, n;
  double a, b, result;
  char ch;

  printf("Enter no. of Elements: ");
  scanf("%d", &n);

  for(i = 0; i < n; i++){
    //scan elements from user
    scanf(" %c ", &ch);

    //if input value is digit then push it int stack
    if(isdigit(ch)){
      push(ch-48);

    }
    //else if element is an operator pop elements from stack and
    //perform operation on them and store in stack
    else{
      a = pop();
      b = pop();

      result = eval(a, b, ch);
      push(result);
    }
  }
  return result;
}

int main(){
    printf("%.2lf",expr());

  return 0;
}
