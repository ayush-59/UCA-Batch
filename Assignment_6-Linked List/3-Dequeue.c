/*
 * Problem-3: Implement a double ended queue Deque
 * Ayush Singh 1910990059 19/08/21
 * Assignment_6 -> Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Deque{
  struct Node *front, *rear;
};

typedef struct Node Node;
typedef struct Deque Deque;

Deque *createDeque(){
  Deque *dq = (Deque*)malloc(sizeof(Deque));
  dq->front = dq->rear = NULL;
  return dq;
}

Node *createNode(){
  Node *node = (Node*)malloc(sizeof(Node));
  node->next = node->prev = NULL;
  return node;
}
int is_empty(Deque *dq){
  return dq->front == NULL || dq->rear == NULL;
}
void pushHead(Deque *dq, int data){
  Node *node = createNode();
  node->data = data;

  if(is_empty(dq)){
    dq->front = dq->rear = node;
  }
  else{
    node->next = dq->front;
    dq->front->prev = node;
    dq->front = node;
  }
}

void pushTail(Deque *dq, int data){
  Node *node = createNode();
  node->data = data;

  if(is_empty(dq)){
    dq->front = dq->rear = node;
  }
  else{
    node->prev = dq->rear;
    dq->rear->next = node;
    dq->rear = node;
  }
}

int popHead(Deque *dq){
  if(is_empty(dq))
    return -1;

  int data = dq->front->data;
  dq->front = dq->front->next;
  if(!is_empty(dq))
    dq->front->prev = NULL;
  else
    dq->rear = NULL;

  return data;

}

int popTail(Deque *dq){
  if(is_empty(dq))
    return -1;

  int data = dq->rear->data;
  dq->rear = dq->rear->prev;
  if(!is_empty(dq))
    dq->rear->next = NULL;
  else
    dq->front = NULL;

  return data;
}

int peekHead(Deque *dq){
  if(is_empty(dq))
    return -1;

  int data = dq->front->data;
  return data;
}

int peekTail(Deque *dq){
  if(is_empty(dq))
    return -1;

  int data = dq->rear->data;
  return data;
}

void show(Deque *dq){
    Node *curr = dq->front;
    printf("\n");
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main(){
  Deque *dq = createDeque();

  pushHead(dq, 1);
  pushHead(dq, 2);
  pushTail(dq, 3);
  pushTail(dq, 4);
  show(dq);
  printf("%d ", popHead(dq));
  printf("%d ", popHead(dq));
  printf("%d ", popTail(dq));
  printf("%d ", popTail(dq));

  show(dq);
}
