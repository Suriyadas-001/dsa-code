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

int isBST(struct Node* root){
    static struct Node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left))
            return 0;
        if(prev!=NULL && root->data<=prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }else
        return 1;
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

    printf("The In-Order Traversal is :: \n");
    inOrderTraversal(root);
    printf("\n");


    if(isBST(root))
        printf("It is a BST\n");
    else
        printf("It is not a BST\n");
    return 0;
}