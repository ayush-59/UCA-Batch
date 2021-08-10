/*
 * Problem-6: Sliding Window
 * Ayush Singh 1910990059 07/08/21
 * Assignment_4 -> Stack and Queue
*/

typedef struct {
    int front;
    int rear;
    int *arr;
    int size;
} Dequeue;

Dequeue *createDequeue(){
    Dequeue *obj = (Dequeue *)malloc(sizeof(Dequeue));
    obj->front = 0;
    obj->rear = -1;
    obj->size = 100000;
    obj->arr = (int*)calloc(obj->size, sizeof(int));

    return obj;
}
int isEmpty(Dequeue *dq){
    if(dq->rear == -1)
        return 1;
    return 0;
}

void insertFront(Dequeue *dq, int val){
    if(dq->front == 0){
        dq->front = dq->size-1;
    }else{
        dq->front--;
    }
    dq->arr[dq->front] = val;
}

void insertRear(Dequeue *dq, int val){
    if(dq->rear == dq->size-1){
        dq->rear = 0;
    }else{
        dq->rear++;
    }
    dq->arr[dq->rear] = val;
}

void deleteFront(Dequeue *dq){
    if(dq->front == dq->rear){
        dq->front = 0;
        dq->rear = -1;
    }else if(dq->front == dq->size-1){
        dq->front = 0;
    }else{
        dq->front++;
    }
}

void deleteRear(Dequeue *dq){
    if(dq->rear == dq->front){
        dq->front = 0;
        dq->rear = -1;
    }else if(dq->rear == 0){
        dq->rear = dq->size-1;
    }else{
        dq->rear--;
    }
}

int peekFront(Dequeue *dq){
    return dq->arr[dq->front];
}

int peekRear(Dequeue *dq){
    return dq->arr[dq->rear];
}


int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    *returnSize = numsSize-k+1;
    int *arr = (int*)calloc(*returnSize, sizeof(int));
        Dequeue *dq= createDequeue();
        for(int i=0;i<k;i++){
            while(!isEmpty(dq) && nums[peekRear(dq)]<=nums[i]){
                deleteRear(dq);
            }
            insertRear(dq, i);
        }
        int n=0;
        for(int i=k;i<numsSize;i++){
            arr[n]=nums[peekFront(dq)];
            while(!isEmpty(dq) && peekFront(dq)<=i-k){
                deleteFront(dq);
            }
             while(!isEmpty(dq) && nums[peekRear(dq)]<=nums[i]){
                deleteRear(dq);
            }
            insertRear(dq, i);
            n++;
        }
        arr[n]=nums[peekFront(dq)];
        return arr;

}
