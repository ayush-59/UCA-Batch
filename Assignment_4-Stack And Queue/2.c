/*
 * Problem-2: Infix to Postfix: Write a program that converts an arithmetic
   expression from infix notation to postfix notation. 
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

char pop(struct Stack **Top){
  if(!*Top){
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

char* infix_to_postfix(char *str, int size){
  char *res = (char *)calloc(size, sizeof(char));
  struct Stack *stack = NULL;
  int i, k=0;

  for(i = 0; i < size; i++){
    if(str[i] >= 48 && str[i] <= 57){
      res[k++] = str[i];
    }
    else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' )
      push(&stack, str[i]);
    else if(str[i] == ')'){
      res[k++] = pop(&stack);
    }
  }
  res[k] = '\0';
  return res;
}

int main(){
  char str[50], *res;
  int size;

  fgets(str, 50, stdin);
  size = sizeof(str)/sizeof(*str);
  res = infix_to_postfix(str, size);

  printf("Postfix : %s",res);
}
