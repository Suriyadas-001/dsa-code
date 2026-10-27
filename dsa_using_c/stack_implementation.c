#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int* arr;
};


// in c language 0/-0 means false and 1,2,3,...../-1,-2,-3...... means true

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1)
        return 1;
    return 0;
}

int isEmpty(struct stack* ptr){
    if(ptr->top == -1)
        return 1;
    return 0;
}

void traversStack(struct stack* ptr){
    if(isEmpty(ptr))
        printf("Stack is empty\n");
    else{
        printf("The elements are ::\n");
        for(int i=0;i<=ptr->top;i++)
            printf("Element[%d] :: %d\n",i,ptr->arr[i]);
    }
}

void push(struct stack* ptr,int data){
    if(isFull(ptr))
        printf("Overflow\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
        printf("The element is inserted\n");
    }
}

void pop(struct stack* ptr){
    if(isEmpty(ptr))
        printf("Underflow\n");
    else{
        ptr->top--;
        printf("The element is poped\n");
    }    
}

int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));


    push(s,78);
    push(s,65);
    push(s,89);
    traversStack(s);
    pop(s);
    push(s,55);
    push(s,28);
    push(s,99);
    traversStack(s);
    push(s,100);
    pop(s);
    traversStack(s);
    pop(s);
    pop(s);
    pop(s);
    traversStack(s);
    pop(s);
    traversStack(s);
    pop(s);

    return 0;
}