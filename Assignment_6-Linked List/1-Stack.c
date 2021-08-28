/*
 * Problem-1: Implement Stack
 * Ayush Singh 1910990059 18/08/21
 * Assignment_6 -> Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Stack{
  int data;
  struct Stack *next;
};

struct Stack *createNode(){
  struct Stack *node = (struct Stack *)malloc(sizeof(struct Stack));
  node->data = 0;
  node->next = NULL;
  return node;
}

int is_empty(struct Stack *top){
  return top == NULL;
}

void push(struct Stack **top, int val){
  struct Stack *node = createNode();
  node->data = val;
  node->next = *top;
  *top = node;
}

int pop(struct Stack **top){
  if(is_empty(*top))
    return -1;

  struct Stack *temp = *top;
  *top = (*top)->next;

  return temp->data;
}

int peek(struct Stack **top){
  if(is_empty(*top))
    return -1;

  return (*top)->data;
}

int main(){
  struct Stack *stack = NULL;
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  printf("%d",pop(&stack));
  printf("%d",pop(&stack));
}
