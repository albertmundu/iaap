#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int balanceFactor;
    int height;
} node_t;


node_t *newnode(int data) {
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->balanceFactor = 0;
    temp->height = 0;
    return temp;
}

node_t *insert(node_t *root, int data) {
    if(!root)
        root = newnode(data);
    else if(data < root->data) {
        //root->balanceFactor = balanceFactor(root);
        root->left = insert(root->left, data);
        root->height = root->left->height + 1;
    }
    else if(data > root->data) {
        //root->balanceFactor = balanceFactor(root);
        root->right = insert(root->right, data);
        root->height = root->right->height + 1;
    }
    return root;
}

void preOrder(node_t *root) {
    if(!root) return;
    printf("%d %d %d\n", root->data, root->height, root->balanceFactor);
    preOrder(root->left);
    preOrder(root->right);
}

int main(int argc, char *argv[]) {
    node_t *root = NULL;
    int n, i, data;
    scanf("%d", &n);
    int A[n];
    for(i=0; i<n; ++i) {
        scanf("%d", &data);
        A[i] = data;
        root = insert(root, A[i]);
    }
    preOrder(root);
    return 0;
}