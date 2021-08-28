/*
 * Problem-2: Implement Queue
 * Ayush Singh 1910990059 18/08/21
 * Assignment_6 -> Linked List
*/

#include <stdio.h>
#include <stdlib.h>


struct Node{
  int data;
  struct Node *next;
};

struct Queue{
  struct Node *front, *rear;
};

typedef struct Queue Queue;
typedef struct Node Node;

Queue* createQueue(){
  Queue *queue = (Queue*)malloc(sizeof(Queue));
  queue->front = queue->rear = NULL;

  return queue;
}

Node* createNode(){
  Node *node = (Node*)malloc(sizeof(Node));
  node->data = 0;
  node->next = NULL;

  return node;
}

int is_empty(Queue *queue){
  return queue->front == NULL;
}

void enqueue(Queue *queue, int data){
  Node *node = createNode();
  node->data = data;

  if(is_empty(queue)){
      queue->front = node;
      queue->rear = node;
  }
  else{
      queue->rear->next = node;
      queue->rear = node;
  }

}

int dequeue(Queue *queue){
  if(is_empty(queue))
    return -1;
  int data = queue->front->data;
  queue->front = queue->front->next;

  return data;
}

int peek(Queue *queue){
  if(is_empty(queue))
    return -1;
  int data = queue->front->data;
  return data;
}

int main(){
  Queue *queue = createQueue();

  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  printf("%d ", dequeue(queue));
  printf("%d ", dequeue(queue));
  enqueue(queue, 4);
  printf("%d ", dequeue(queue));
  printf("%d ", peek(queue));
}
