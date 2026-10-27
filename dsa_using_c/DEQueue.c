#include<stdlib.h>
#include<stdio.h>
struct queue{
    int capacity;
    int size;
    int lfront;
    int rfront;
    int lrear;
    int rrear;
    int* arr;
};
int isFull(struct queue* Q){
    return Q->size == Q->capacity;
}
int isEmpty(struct queue* Q){
    return Q->size == 0;
}
void insertAtLeft(struct queue* Q,int data){
    if(isFull(Q))
        printf("Overflow\n");
    else{
        Q->arr[Q->lrear] = data;
        Q->size++;
        Q->lrear++;
    }
}
int deleteAtLeft(struct queue* Q){
    int data = -1;
    if(isEmpty(Q))
        printf("Underflow\n");
    else{
        data = Q->arr[Q->lfront];
        Q->lfront++;
        Q->size--;
    }
    return data;
}
void insertAtRight(struct queue* Q,int data){
    if(isFull(Q))
        printf("Overflow\n");
    else{
        Q->arr[Q->rrear] = data;
        Q->rrear--;
        Q->size++;
    }
}
int deleteAtRight(struct queue* Q){
    int data = -1;
    if(isEmpty(Q))
        printf("Underflow\n");
    else{
        data = Q->arr[Q->rfront];
        Q->rfront--;
        Q->size--;
    }
}
void traverse(struct queue* Q){
    if(Q->size == 0)
        printf("DEQueue is empty !!!\n");
    else{
        printf("\nThe elements are :: ");
            // for left side element
        for(int i=Q->lfront;i<Q->lrear;i++)
            printf("%d ",Q->arr[i]);
        // for right side element
        for(int i=Q->rrear+1;i<=Q->rfront;i++)
            printf("%d ",Q->arr[i]);
        printf("\n");
    }
}
int main(){
    struct queue* Q = (struct queue*)malloc(sizeof(struct queue));
    Q->capacity = 5;
    Q->size = 0;
    Q->lrear = Q->lfront = 0;
    Q->rrear = Q->rfront = Q->capacity-1;
    Q->arr = (int*)malloc(Q->capacity*sizeof(int));
    traverse(Q);
    insertAtLeft(Q,5);
    insertAtLeft(Q,6);
    traverse(Q);
    insertAtRight(Q,8);
    insertAtRight(Q,9);

    traverse(Q);
    deleteAtLeft(Q);
    deleteAtRight(Q);
    traverse(Q);
    return 0;
}