#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char* arr;
};

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

void push(struct stack* ptr,char data){
    if(isFull(ptr))
        printf("Overflow\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(struct stack* ptr){
    char ch;
    if(isEmpty(ptr))
        return -1;
    else{
        ch = ptr->arr[ptr->top];
        ptr->top --;
        return ch;
    }    
}

int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int precedence(char ch){
    if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch){
    if(ch == '*' || ch == '/' || ch == '-' || ch == '+')
        return 1;
    return 0;
}

char* infixToPostfix(char* infix){
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    char* postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0; //Track infix traversal
    int j=0; // Track postfix addition
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){ // if infix[i] is not a operator(+/- etc)
            postfix[j] = infix[i];
            j++;
            i++;
        }else{
            if(isEmpty(sp) || precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    // code
    char* infix = "a+b/c*d-e";
    // char* infix = "x-y/z-k*d";
    // char* infix = "a-b+t/6";
    printf("Postfix is %s",infixToPostfix(infix));
    return 0;
}