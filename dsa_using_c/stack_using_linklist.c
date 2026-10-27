#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* stack = NULL; // global declaration

int isEmpty(){
    if(stack==NULL)
        return 1;
    return 0;
}

int isFull(struct Node* newNode){
    if(newNode == NULL)
        return 1;
    return 0;
}

void push(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(isFull(newNode))
        printf("Overflow\n");
    else{
        newNode->data = data;
        newNode->next = stack;
        stack = newNode;
    }    
}

int pop(){
    int x;
    if(isEmpty()){
        printf("Underflow\n");
        return -1;
    }else{
        x = stack->data;
        struct Node* temp = stack;
        stack = stack->next;
        free(temp);
    }
    return x;
}

void traverse(){
    struct Node* top = stack;
    if(top == NULL)
        printf("Stack is emtpy\n");
    else{
        while(top!=NULL){
            printf("Element :: %d\n",top->data);
            top = top->next;
        }
    }
}

int peek(){
    if(stack == NULL){
        printf("Stack is emtpy\n");
        return -1;
    }else{
        return stack->data;
    } 
}

int main(){
    struct Node* stack = NULL;

    traverse(stack);
    push(78);
    push(32);
    push(12);
    traverse();
    printf("Popped element %d\n",pop());
    push(92);
    traverse();

    printf("top element %d\n",peek());
    return 0;
}