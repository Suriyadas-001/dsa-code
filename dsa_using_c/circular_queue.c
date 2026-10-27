#include<stdio.h>
#include<stdlib.h>
struct CircularQueue{
    int size;
    int capacity;
    int front;
    int rear;
    int* arr;
};
int isFull(struct CircularQueue* Q){
    if(Q->size == Q->capacity)
        return 1;
    return 0;
}
int isEmpty(struct CircularQueue* Q){
    if(Q->size == 0)
        return 1;
    return 0;
}
void Enqueue(struct CircularQueue* Q,int data){
    if(isFull(Q))
        printf("Overflow\n");
    else{
        Q->arr[Q->rear] = data;
        Q->rear = (Q->rear+1)%Q->capacity;
        Q->size++;
    }
}
int Dequeue(struct CircularQueue* Q){
    int data = -1;
    if(isEmpty(Q))
        printf("Underflow\n");
    else{
        data =  Q->arr[Q->front];
        Q->front = (Q->front+1)%Q->capacity;
        Q->size--;
    }
    return data;
}
void traverse(struct CircularQueue* Q){
    if(isEmpty(Q))
        printf("Queue is Empty\n");
    else{
        int i=0;
        int temp = Q->front;
        printf("Element :: ");
        while(i<Q->size){
            printf("%d\t",Q->arr[temp]);
            temp = (temp+1)%Q->capacity;
            i++;
        }
        printf("\n");
    }
}
int main(){
    struct CircularQueue* Q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    Q->size = 0;
    Q->capacity = 5;
    Q->rear = Q->front = 0;
    Q->arr = (int*)malloc(Q->capacity*sizeof(int));
    
    traverse(Q);
    printf("Deleted element %d\n", Dequeue(Q));
    Enqueue(Q,75);
    Enqueue(Q,43);
    traverse(Q);
    printf("Deleted element %d\n", Dequeue(Q));
    Enqueue(Q,64);
    Enqueue(Q,16);
    Enqueue(Q,95);
    Enqueue(Q,36);
    traverse(Q);
    Enqueue(Q,51);
    traverse(Q);
    printf("Deleted element %d\n", Dequeue(Q));
    traverse(Q);
    Enqueue(Q,62);
    traverse(Q);


    free(Q->arr);
    free(Q);
    return 0;
}