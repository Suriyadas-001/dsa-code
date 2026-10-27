#include<stdio.h>
#include<stdlib.h>

// self referential structure
struct Node{
    int data;
    struct Node* next;
};

// function for linklist traversal
void linklistTraversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("Element :: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    // linklist creation
    // Define node
    struct Node* head;
    struct Node* middle;
    struct Node* tail;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    middle = (struct Node*)malloc(sizeof(struct Node));
    tail = (struct Node*)malloc(sizeof(struct Node));

    // store data
    head->data = 9;
    head->next = middle;
    middle->data = 13;
    middle->next = tail;
    tail->data = 18;
    tail->next = NULL;

    // call traversal function
    linklistTraversal(head);
} 