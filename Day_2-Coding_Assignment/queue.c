/*
 * Problem-1: Implement a Queue in C
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
  struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = 0;
  queue->rear = -1;
  queue->arr = (int*)calloc(capacity, sizeof(int));
  return queue;
}

// Queue is empty when front is greater than rear
//Time Complexity: O(1)
int is_empty(struct Queue *queue){
  return queue->front > queue->rear;
}

// Queue is full when top is equal to the last index
//Time Complexity: O(1)
int is_full(struct Queue *queue){
  return queue->rear == queue->capacity - 1;
}

// Function to add an item to queue.  It increases rear by 1
//Time Complexity: O(1)
void enqueue(struct Queue *queue, int item){
  if(is_full(queue)){
    printf("Queue Overflow!");
    return;
  }
  queue->arr[++queue->rear] = item;

}

// Function to remove an item from queue.  It increases front by 1
//Time Complexity: O(1)
int dequeue(struct Queue *queue){
  if(is_empty(queue)){
    printf("Queue Underflow!");
    return -1;
  }
  return queue->arr[queue->front++];

}

// Function to return the first item from queue without removing it
//Time Complexity: O(1)
int peek(struct Queue *queue){
  if(is_empty(queue)){
    printf("Queue Underflow!");
    return -1;
  }
  return queue->arr[queue->front];
}

//Function to print the Queue
//Time Complexity: O(n)
void show(struct Queue *queue){
    int i;

    printf("\nQueue: ");
    for(i = queue->front; i <= queue->rear; i++)
      printf("%d ", queue->arr[i]);
}

int main(){
  int capacity = 5;
  struct Queue *queue = create_queue(capacity);

  enqueue(queue, 1);
  enqueue(queue, 2);
  printf("%d ", peek(queue));
  enqueue(queue, 3);

  show(queue);
  printf("\n");
  printf("%d ", dequeue(queue));
  printf("%d ", peek(queue));
  enqueue(queue, 5);

  show(queue);
  enqueue(queue, 9);

  show(queue);
  enqueue(queue, 8);


  return 0;
}
