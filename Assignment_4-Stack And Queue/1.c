/*
 * Problem-1: Balanced Parentheses: Write a program that checks whether the
   sequence of brackets in the given string is balanced or not.
 * Ayush Singh 1910990059 07/08/21
 * Assignment_4 -> Stack and Queue
*/

#include <stdio.h>
#include <stdlib.h>

struct Stack {
  char data;
  struct Stack *next;
};

struct Stack *create_node(char data){
  struct Stack *node = (struct Stack *)malloc(sizeof(struct Stack));
  node->data = data;
  node->next = NULL;
  return node;
}

void push(struct Stack **Top, char data){
  struct Stack *new_node = create_node(data);

  if(*Top == NULL)
    *Top = new_node;
  else{
    new_node->next = *Top;
    *Top = new_node;
  }

}
int is_empty(struct Stack **Top){
    return !*Top;
}

char pop(struct Stack **Top){
  if(is_empty(Top)){
    printf("Underflow!");
    return -1;
  }
  char data = (*Top)->data;
  *Top = (*Top)->next;
  return data;
}

void show(struct Stack **Top){
  struct Stack *curr = *Top;
  while(curr != NULL){
    printf("%d ", curr->data);
    curr = curr->next;
  }
}

int is_couple(char a, char b){
  return ((a == '[' && b == ']') || (a == '(' && b == ')') || (a == '{' && b == '}') );
}

int is_balanced(char *str){
  struct Stack *stack = NULL;
  int i;
  char ele;

  for(i = 0; str[i] != '\0'; i++){
    if(str[i] == '(' || str[i] == '{' || str[i] == '[')
      push(&stack, str[i]);
    else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
      ele = pop(&stack);
      if(!is_couple(ele, str[i]))
        return 0;
    }
  }
  if(!is_empty(&stack))
    return 0;
  return 1;
}

int main(){
  char str[50];
  int res;

  fgets(str, 50, stdin);
  res = is_balanced(str);

  if(res)
    printf("True");
  else
    printf("False");
}
