#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* evenLinklist(struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->data = data;
        new->next = NULL;
    if(head == NULL){
        head = new;
    }
    else{
        struct Node* ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

struct Node* oddLinklist(struct Node* head,int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
        new->data = data;
        new->next = NULL;
    if(head != NULL)
        new->next = head;
    return new;
}

void traverse(struct Node* list){
    while(list!=NULL){
        printf("element :: %d\n",list->data);
        list = list->next;
    }
}

void selection_sort(int arr[],int n){
    int min_index;
    for(int i=0; i<n-1; i++){
        min_index = i;
        for(int j=i+1;j<n;j++){
            if(arr[min_index]>arr[j]){
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    int n=12;
    int arr[] = {37,78,15,56,91,72,23,88,65,95,42,48};
    struct Node* even = (struct Node*)malloc(sizeof(struct Node));
    struct Node* odd = (struct Node*)malloc(sizeof(struct Node));
    even = NULL;
    odd = NULL;
    selection_sort(arr,n);
    
    for(int i=0;i<12;i++){
        if(arr[i]%2==0){
            even = evenLinklist(even,arr[i]);
        }
        else{
            odd = oddLinklist(odd,arr[i]);
        }
    }


    printf("Even linklist Ascending order ::\n");
    traverse(even);
    printf("Odd linklist Descending order ::\n");
    traverse(odd);

    return 0;
}