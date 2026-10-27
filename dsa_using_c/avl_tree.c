#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int a,int b){
    return a>b?a:b;
}
int getHeight(struct Node *root){
    if(root==NULL)
        return 0;
    return root->height;
}
struct Node *createNode(int data){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
int getBalanceFactor(struct Node *node){
    if (node==NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
struct Node* rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right),getHeight(y->left))+1;
    x->height = max(getHeight(x->right),getHeight(x->left))+1;
    return x;
}
struct Node* leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right),getHeight(y->left))+1;
    x->height = max(getHeight(x->right),getHeight(x->left))+1;
    return y;
}
struct Node* insertInAvlTree(struct Node *root,int data){
    if(root==NULL)
        return createNode(data);
    if(data<root->data)
        root->left = insertInAvlTree(root->left,data);
    else if(data>root->data)
        root->right = insertInAvlTree(root->right,data);
    root->height = max(getHeight(root->right),getHeight(root->left))+1;
    int bf = getBalanceFactor(root);

    // Left Left Case
    if(bf>1 && data < root->left->data){
        return rightRotate(root);
    }
    // Right Right Case
    if(bf<-1 && data > root->right->data){
        return leftRotate(root);
    }
    // Left Right Case
    if(bf>1 && data > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    if(bf<-1 && data < root->right->data){
        root->right = leftRotate(root->right);
        return rightRotate(root);
    }
    return root;
}
void preOrderTraversal(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
int main(){
    struct Node *root = NULL;
    root = insertInAvlTree(root,1);
    root = insertInAvlTree(root,2);
    root = insertInAvlTree(root,3);
    root = insertInAvlTree(root,4); 
    root = insertInAvlTree(root,5);
    root = insertInAvlTree(root,6);
    preOrderTraversal(root);
    return 0;
}