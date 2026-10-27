#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void traversCircularLinklist(struct Node* head){
    struct Node* ptr = head;
    do{
        printf("Element :: %d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

struct Node* circularLinklist(int n,int arr[]){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;
    head->data = arr[0];
    int i=1;
    while(i<n){
        struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->data = arr[i];
        temp->next = new;
        temp = temp->next;
        i++;
    }
    temp->next = head;
    return head;
}

struct Node* insertAtBeg(struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;
    new->data = data;
    do{
        ptr = ptr->next;
    }while(ptr->next!=head);
    ptr->next = new;
    new->next = head;
    return new;
}

int main(){
    int n=5,arr[] = {5,6,9,1,3};
    struct Node* head = circularLinklist(n,arr);
    head = insertAtBeg(head,2);
    traversCircularLinklist(head);
    return 0;
}