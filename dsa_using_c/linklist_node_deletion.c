#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void createNode(struct Node* ptr,int n,int arr[]){
    for(int i=1;i<n;i++){
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->data = arr[i-1];
        new->next = NULL;
        ptr->next = new;
        ptr = ptr->next;
    }
}

// traversal linklist
void linklistTraversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("Element :: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

// Delete first Node
struct Node* deleteFirstNode(struct Node* ptr){
    struct Node* p=ptr;
    ptr = ptr->next;
    free(p);
    return ptr;
}

// Delete any node
void deleteAtMiddle(struct Node* ptr,int index){
    struct Node* p;
    int i = 0;
    while(i<index-1){
        ptr = ptr->next;
        i++;
    }
    p = ptr->next;
    ptr->next = p->next;
    free(p);
}

// delete last node
void deleteLastNode(struct Node* ptr){
    while(ptr->next->next!=NULL){
        ptr = ptr->next;
    }
    struct Node* p = ptr->next;
    ptr->next = NULL;
    free(p);
}

int main(){
    struct Node* head;
    head->data = 30;
    head->next = NULL;
    // create linklist
    int n = 7;
    int arr[] = {45,98,32,15,23,41};
    createNode(head,n,arr);

    // head = deleteFirstNode(head);
    // deleteAtMiddle(head,3);
    deleteLastNode(head);
    linklistTraversal(head);
}