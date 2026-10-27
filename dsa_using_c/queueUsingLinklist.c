#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int data;
    struct Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

int isEmpty(struct Queue* ptr){
    return ptr == NULL;
}
int isFull(struct Queue* newNode){
    return newNode == NULL;
}
void traverse(){
    struct Queue* ptr = front;
    if(!isEmpty(ptr)){
        printf("Elements are :: ");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
        return;
    }
    printf("Queue is empty!\n");
}
void enQueue(int data){
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    if(isFull(newNode))
        printf("Overflow\n");
    else{
        newNode->data = data;
        newNode->next = NULL;
        if(isEmpty(front))
            rear = front = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }    
    }   
}
int deQueue(){
    int data = -1;
    if(isEmpty(front)){
        printf("Underflow\n");
        return -1;
    }else{
        data = front->data;
        struct Queue* ptr = front;
        front = front->next;
        if(front == NULL)
            rear == NULL;
        free(ptr);
        return data;
    }
}

int main(){
    traverse();
    enQueue(56);
    enQueue(97);
    traverse();
    deQueue();
    enQueue(17);
    enQueue(63);
    enQueue(38);
    enQueue(30);
    traverse();

    return 0;
}