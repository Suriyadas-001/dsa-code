#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char* arr;
};

void push(struct stack* ptr,char data){
    if(ptr->top == ptr->size-1)
        printf("Overflow");
    else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

char pop(struct stack* ptr){
    if(ptr->top == -1)
        return -1;
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int stacktop(struct stack* ptr){
    return ptr->arr[ptr->top];
}

int isOperator(char ch){
    if(ch == '/' || ch == '*' || ch == '+' || ch == '-')
        return 1;
    return 0;
}

int precedence(char ch){
    if(ch == '/' || ch == '*')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

char* infixToPrefix(char* infix){
    int length = strlen(infix); // length of infix expression
    char* prefix = (char*)malloc((length+1)*sizeof(char));
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    
    // creating stack
    sp->size = 15;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));

    int i = length-1;
    int j = i;
    while(i>=0){
        if(!isOperator(infix[i])){
            prefix[j] = infix[i];
            i--;
            j--;
        }else{
            if(sp->top == -1 || precedence(infix[i])>=precedence(stacktop(sp))){
                push(sp,infix[i]);
                i--;
            }else{
                prefix[j] = pop(sp);
                j--;
            }
        }
    }
    while(sp->top!=-1){
        prefix[j] = pop(sp);
        j--;
    }
    prefix[length] = '\0';
    return prefix;
}
int main(){
    char* infix = "a+b/c-d*e-f";
    printf("Infix expression => %s\n",infix);
    printf("Prefix expression => %s\n",infixToPrefix(infix));
    return 0;
}