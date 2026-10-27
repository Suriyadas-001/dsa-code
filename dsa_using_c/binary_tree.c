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
void preOrderTraversal(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct Node* root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}
void inOrderTraversal(struct Node* root){
    if(root!=NULL){
        inOrderTraversal(root->left); 
        printf("%d ",root->data);
        inOrderTraversal(root->right);
    }
}
int main(){
    struct Node* root = createNode(4);
    struct Node *A,*B,*C,*D,*E; // It means A is pointer only and B,C,D,E are normal variable
    A = createNode(9);
    B = createNode(1);
    root->left = A;
    root->right = B;
    C = createNode(3);
    A->left = C;
    D = createNode(7);
    E = createNode(5);
    B->left = D;
    B->right = E;

    // Tree Traversal
    printf("The Pre-Order Traversal is :: \n");
    preOrderTraversal(root);
    printf("\n");

    printf("The Post-Order Traversal is :: \n");
    postOrderTraversal(root);
    printf("\n");

    printf("The In-Order Traversal is :: \n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}