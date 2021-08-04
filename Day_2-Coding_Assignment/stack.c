/*
 * Problem-1: Implement a Stack in C
 * Ayush Singh 1910990059 03/08/21
 * Day_2_Coding_Assignment
*/
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack{
  int capacity;
  int top;
  int *arr;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *create_stack(int capacity){
  struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->arr = (int*)calloc(capacity, sizeof(int));
  return stack;
}

// Stack is empty when top is equal to -1
//Time Complexity: O(1)
int is_empty(struct Stack *stack){
  return stack->top == -1;
}

// Stack is full when top is equal to the last index
// Time Complexity: O(1)
int is_full(struct Stack *stack){
  return stack->top == stack->capacity - 1;
}

// Function to add an item to stack.  It increases top by 1
// Time Complexity:
// O(1) - normal cases
// O(n) - when stack full
void push(struct Stack *stack, int item){
  // If Stack is full increase double the capacity of stack
  if(is_full(stack)){
    int *temp_Arr = (int *)calloc(stack->capacity * 2, sizeof(int));

    for(int i = 0; i <= stack->top; i++){
      temp_Arr[i] = stack->arr[i];
    }
    stack->arr = temp_Arr;
    stack->capacity *= 2;
  }
  stack->arr[++stack->top] = item;

}

// Function to remove an item from stack.  It decreases top by 1
// Time Complexity: O(1)
int pop(struct Stack *stack){
  if(is_empty(stack)){
    printf("Stack Underflow!");
    return -1;
  }
  return stack->arr[stack->top--];

}

// Function to return the top from stack without removing it
// Time Complexity: O(1)
int peek(struct Stack *stack){
  if(is_empty(stack)){
    printf("Stack Underflow!");
    return -1;
  }
  return stack->arr[stack->top];
}

void show(struct Stack *stack){
    int i;

    printf("\nStack: ");
    for(i = stack->top; i >= 0; i--){
        printf("%d ",stack->arr[i]);
    }
}

int main(){
  int capacity = 2;
  struct Stack *stack = create_stack(capacity);

  push(stack, 1);
  push(stack, 2);
  printf("%d ", peek(stack));
  push(stack, 3);
  push(stack, 4);
  show(stack);
  printf("\n%d ", pop(stack));
  printf("%d ", peek(stack));
  push(stack, 5);
  show(stack);
  return 0;
}
