/*
 * Problem-3: Stack using 2 Queue
 * Ayush Singh 1910990059 09/08/21
 * Assignment_4 -> Stack and Queue
*/

typedef struct {
    int front;
    int rear;
    int *arr;
} Queue;

Queue* createQueue() {
    Queue *obj = (Queue*)malloc(sizeof(Queue));
    obj->arr = (int*)calloc(100, sizeof(int));
    obj->front = 0;
    obj->rear = -1;
    return obj;
}

void queuePush(Queue *q, int x) {
    q->arr[++q->rear] = x;
}

int queuePop(Queue *q) {
    return q->arr[q->front++];
}

int isEmptyQueue(Queue *q) {
    return q->front > q->rear;
}


void showQueue(Queue *q) {
    for(int i = q->front; i <= q->rear; i++) {
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

void swapQueue(Queue **q1, Queue **q2) {
    Queue *temp = *q1;
    *q1 = *q2;
    *q2 = temp;

}
typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q1 = createQueue();
    obj->q2 = createQueue();

    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    queuePush(obj->q1, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int ele;
    while(1) {
        ele = queuePop(obj->q1);
        if(isEmptyQueue(obj->q1))
            break;
        queuePush(obj->q2, ele);
    }
    swapQueue(&obj->q1, &obj->q2);
    return ele;
}


/** Get the top element. */
int myStackTop(MyStack* obj) {
    int ele;
    while(!isEmptyQueue(obj->q1)) {
        ele = queuePop(obj->q1);
        queuePush(obj->q2, ele);
    }


    swapQueue(&obj->q1, &obj->q2);

    return ele;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
  return isEmptyQueue(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
