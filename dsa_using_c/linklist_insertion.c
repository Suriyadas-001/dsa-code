#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};


// traversal linklist
void linklistTraversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("Element :: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

// insert at the head of the linklist
struct Node* insertAtFirst(struct Node* ptr,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = ptr;
    return new;
}

// insert at n index
void insertAtIndex(struct Node* ptr,int data,int index){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));

    new->data = data;
    int i=1;
    while(i != index-1){
        ptr=ptr->next;
        i++;
    }
    new->next = ptr->next;
    ptr->next = new;  
}


// insert at end
void insertAtEnd(struct Node* ptr,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = new;
    new->next=NULL;
}

// insert after a given node
void insertAfterNode(struct Node* ptr,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = ptr->next;
    ptr->next = new;
}

// create linklist of n node
void createNode(struct Node* ptr,int n,int arr[]){
    for(int i=1;i<n;i++){
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->data = arr[i-1];
        new->next = NULL;
        ptr->next = new;
        ptr = ptr->next;
    }
}
int main(){
    // memory allocation
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 4;
    head->next = NULL;
    
    // create linklist
    int n = 7;
    int arr[] = {45,98,32,15,23,41};
    createNode(head,n,arr);
    // linklistTraversal(head);

    // insert node into the linklist
    // head = insertAtFirst(head,data);

    // insertAtIndex(head,data,3);

    // insertAtEnd(head,data);

    // insertAfterNode(a,data);

    linklistTraversal(head);
    return 0;
}