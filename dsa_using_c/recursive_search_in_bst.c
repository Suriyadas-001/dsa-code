#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void inOrderTraversal(struct Node* root){
    if(root!=NULL){
        inOrderTraversal(root->left); 
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}
struct Node* recursiveSearch(struct Node *root,int key){
    if(root!=NULL){
        if(root->data == key)
            return root;
        else if(key < root->data)
            return recursiveSearch(root->left,key);
        else
            return recursiveSearch(root->right,key);
    }
    return NULL;
}
struct Node* iterativeSearch(struct Node *root,int key){
    while(root != NULL && root->data != key){
        if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
int main(){
    struct Node *root = createNode(9);
    struct Node *B,*C,*D,*E,*F,*G,*H,*I;
    B = createNode(4);
    C = createNode(11);
    root->left = B;
    root->right = C;
    
    D = createNode(2);
    E = createNode(7);
    F = createNode(15);
    B->left = D;
    B->right = E;
    C->right = F;
    
    G = createNode(5);
    H = createNode(8);
    I = createNode(14);
    E->left = G;
    E->right = H;
    F->left = I;

    // printf("The In-Order Traversal is :: \n");
    // inOrderTraversal(root);
    // printf("\n");

    // recursive search 
    int key = 10;
    struct Node *result = linearSearch(root,key);
    if(result!=NULL)
        printf("%d is found",result->data);
    else
        printf("Element is not found\n");
    return 0;
}