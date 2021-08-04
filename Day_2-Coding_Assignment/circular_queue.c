/*
 * Problem-3: Implement a Circular Queue in C
 * Ayush Singh 1910990059 03/08/21
 * Day_2_Coding_Assignment
*/
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue{
  int capacity, front, rear;
  int *arr;
};

// function to create a queue of given capacity. It initializes size of
// queue as 0
struct Queue *create_queue(int capacity){
  struct Queue *cir_queue = (struct Queue*)malloc(sizeof(struct Queue));
  cir_queue->capacity = capacity;
  cir_queue->front = 0;
  cir_queue->rear = -1;
  cir_queue->arr = (int*)calloc(capacity, sizeof(int));
  return cir_queue;
}

// Queue is empty when rear is -1
// Time Complexity: O(1)
int is_empty(struct Queue *cir_queue){
  return cir_queue->rear == -1;
}

// Queue is full when front is just after rear or when rear - front = capacity-1
// Time Complexity: O(1)
int is_full(struct Queue *cir_queue){
  return (cir_queue->rear != -1 && cir_queue->rear == cir_queue->front - 1) ||
          cir_queue->rear - cir_queue->front == cir_queue->capacity - 1;
}

// Function to add an item to queue.If rear = capacity-1 then rear is changed
// to 0 else increases rear by 1 and puts element on rear
// Time Complexity: O(1)
void enqueue(struct Queue *cir_queue, int item){
  if(is_full(cir_queue)){
    printf("Queue Overflow!");
    return;
  }
  if(cir_queue->rear == cir_queue->capacity - 1)
    cir_queue->rear = 0;
  else
    cir_queue->rear++;
  cir_queue->arr[cir_queue->rear] = item;

}

// Function to remove an item from queue.If front = capacity-1 then front is
// changed to 0 else increases front by 1
// Time Complexity: O(1)
int dequeue(struct Queue *cir_queue){
  if(is_empty(cir_queue)){
    printf("Queue Underflow!");
    return -1;
  }

  int item = cir_queue->arr[cir_queue->front];

  if(cir_queue->front == cir_queue->capacity - 1)
    cir_queue->front = 0;
  // if front = rear then 1 element in queue, after removing it the queue
  // will be empty. So set rear to -1 and front to 0
  else if(cir_queue->front == cir_queue->rear){
    cir_queue->front = 0;
    cir_queue->rear = -1;
  }
  else
    cir_queue->front++;
  return item;

}

// Function to return the first item from cir_queue without removing it
// Time Complexity: O(1)
int peek(struct Queue *cir_queue){
  if(is_empty(cir_queue)){
    printf("Queue Underflow!");
    return -1;
  }
  return cir_queue->arr[cir_queue->front];
}

// Function to print the Queue
// Time Complexity: O(n)
void show(struct Queue *cir_queue){
    int i;

    printf("\nQueue: ");
    if(cir_queue->front <= cir_queue->rear)
      for(i = cir_queue->front; i <= cir_queue->rear; i++)
        printf("%d ", cir_queue->arr[i]);
    else{
      for(i = cir_queue->front; i < cir_queue->capacity; i++)
        printf("%d ", cir_queue->arr[i]);
      for(i = 0; i <= cir_queue->rear; i++)
        printf("%d ", cir_queue->arr[i]);
    }
}

int main(){
  int capacity = 5;
  struct Queue *cir_queue = create_queue(capacity);

  enqueue(cir_queue, 1);
  enqueue(cir_queue, 2);
  printf("%d ", peek(cir_queue));
  enqueue(cir_queue, 3);

  show(cir_queue);
  printf("\n");
  printf("%d ", dequeue(cir_queue));
  printf("%d ", peek(cir_queue));
  enqueue(cir_queue, 5);
  printf("%d ", dequeue(cir_queue));

  show(cir_queue);
  enqueue(cir_queue, 6);

  show(cir_queue);
  enqueue(cir_queue, 7);
  enqueue(cir_queue, 8);

  show(cir_queue);
  enqueue(cir_queue, 9);
  show(cir_queue);
  printf("%d ", dequeue(cir_queue));
  enqueue(cir_queue, 9);
  show(cir_queue);
  return 0;
}
