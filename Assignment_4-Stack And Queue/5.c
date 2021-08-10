/*
 * Problem-5: MinStack
 * Ayush Singh 1910990059 07/08/21
 * Assignment_4 -> Stack and Queue
*/

typedef struct {
    int top;
    int *arr, *min_arr;
    int curr_min;

} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->arr = (int*)calloc(30000, sizeof(int));
    obj->min_arr = (int*)calloc(30000, sizeof(int));
    obj->curr_min = (int)INFINITY;
    obj->top = -1;

    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    if(val < obj->curr_min)
        obj->curr_min = val;
    obj->arr[obj->top] = val;
    obj->min_arr[obj->top] = obj->curr_min;

}

void minStackPop(MinStack* obj) {
  obj->top--;
  if(obj->top == -1)
    obj->curr_min = (int)INFINITY;
  else
    obj->curr_min = obj->min_arr[obj->top];
}

int minStackTop(MinStack* obj) {
  return obj->arr[obj->top];
}

int minStackGetMin(MinStack* obj) {
  return obj->min_arr[obj->top];
}

void minStackFree(MinStack* obj) {
    obj->top=-1;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
