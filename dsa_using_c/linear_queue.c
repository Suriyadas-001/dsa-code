#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int capacity;
    int size;
    int front;
    int rear;
    int* arr;
};

int isFull(struct Queue* Q){
    if(Q->rear == Q->capacity-1)
        return 1;
    return 0;
}

int isEmpty(struct Queue* Q){
    if(Q->rear == Q->front)
        return 1;
    return 0;
}

void EnQueue(struct Queue* Q,int data){
    if(isFull(Q))
        printf("Overflow\n");
    else{
        Q->rear++;
        Q->size++;
        Q->arr[Q->rear] = data;
    }
}

int DeQueue(struct Queue* Q){
    int data = -1;
    if(isEmpty(Q))
        printf("Underflow\n");
    else{
        Q->front++;
        Q->size--;
        data = Q->arr[Q->front];
    }
    return data;
}
void traverse(struct Queue* Q){
    if(isEmpty(Q))
        printf("Queue is empty\n");
    else{
        for(int i=Q->front+1;i<=Q->rear;i++){
            printf("Element %d\n",Q->arr[i]);
        }
    }
}
int main(){
    struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->size = 0;
    Q->capacity = 5;
    Q->front = Q->rear = -1;
    Q->arr = (int*)malloc(Q->capacity*sizeof(int));

    // DeQueue(Q);
    // traverse(Q);
    // EnQueue(Q,10);
    // EnQueue(Q,34);
    // EnQueue(Q,74);
    // traverse(Q);
    // printf("Deleted element :: %d\n",DeQueue(Q));
    // traverse(Q);
    // printf("Deleted element :: %d\n",DeQueue(Q));
    // EnQueue(Q,90);
    // EnQueue(Q,31);
    // EnQueue(Q,86);
    // traverse(Q);
    // printf("Deleted element :: %d\n",DeQueue(Q));
    // printf("Deleted element :: %d\n",DeQueue(Q));
    // EnQueue(Q,65);
    // printf("Deleted element :: %d\n",DeQueue(Q));
    // EnQueue(Q,43);
    // traverse(Q);
    EnQueue(Q,5);
    traverse(Q);
    EnQueue(Q,8);
    traverse(Q);
    DeQueue(Q);
    traverse(Q);
    
    return 0;
}