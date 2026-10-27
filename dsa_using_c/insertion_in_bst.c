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
void insert(struct Node *root,int data){
    struct Node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(data==root->data){
            printf("Cannot insert, already in BST %d\n",data);
            return;
        }
        else if(data<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct Node *new = createNode(data);
    if(data<prev->data){
        prev->left = new;
    }else{
        prev->right = new;
    }
}
int main(){
    struct Node *root = createNode(9);
    struct Node *B,*C,*X,*D,*E,*F,*G,*H,*I;
    B = createNode(4);
    C = createNode(13);
    root->left = B;
    root->right = C;
    
    D = createNode(2);
    E = createNode(7);
    X = createNode(12);
    F = createNode(15);
    B->left = D;
    B->right = E;
    C->right = F;
    C->left = X;
    
    G = createNode(5);
    H = createNode(8);
    I = createNode(14);
    E->left = G;
    E->right = H;
    F->left = I;

    printf("The In-Order Traversal is :: \n");
    inOrderTraversal(root);
    printf("\n");

    insert(root,10);

    printf("The In-Order Traversal is :: \n");
    inOrderTraversal(root);
    printf("\n");
    return 0;
}