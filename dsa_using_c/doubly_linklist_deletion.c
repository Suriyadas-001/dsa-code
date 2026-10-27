#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createDoublyLinklist(int n,int arr[]){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->prev = NULL;

    struct Node* temp = head;
    for(int i=1;i<n;i++){
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->data = arr[i];
        new->prev = temp;
        temp->next = new;
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

void forwardTraversal(struct Node* ptr){
    printf("Forward Traversal ::\n");
    while(ptr!=NULL){
        printf("Element :: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

void backwardTraversal(struct Node* ptr){
    printf("Backward Traversal ::\n");
    while(ptr!=NULL){
        printf("Element :: %d\n",ptr->data);
        ptr = ptr->prev;
    }
}

void deleteAtMid(struct Node* head,int index){
    struct Node* ptr = head;
    int i = 0;
    while(i<index-1){
        ptr = ptr->next;
        i++;
    }
    struct Node* p = ptr;
    ptr = ptr->next;
    ptr->next->prev = p;
    p->next = ptr->next;
    free(ptr);
    printf("\n deleted\n");
}

int main(){
    int n=7,arr[] = {30,45,98,32,15,23,41};
    struct Node* head = createDoublyLinklist(n,arr);
    forwardTraversal(head);
    struct Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    backwardTraversal(tail);
    
    
    deleteAtMid(head,3);
    forwardTraversal(head);
    backwardTraversal(tail);   
    return 0;
}