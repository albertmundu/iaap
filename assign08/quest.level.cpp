#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;


struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

struct node*insert(struct node*root,int data){
    if(root==NULL)
        root=createnode(data);
    else{
        if(data <= root->data)
            root->left=insert(root->left,data);
        else if(data > root->data)
            root->right=insert(root->right,data);
    }
    return root;
}

void level_order(struct node*root){
    if(root){
        queue<struct node*> q;
        q.push(root);
        while(!q.empty()){
            struct node*current=q.front();
            cout<<current->data<<" ";
            if(current->left!=NULL) q.push(current->left);
            if(current->right!=NULL) q.push(current->right);
            q.pop();
        }
        cout<<endl;
    }
}

int main(){
    struct node*root=NULL;
    int n,data;
    cin>>n;
    while(n--){
        cin>>data;
        root=insert(root,data);
    }
    level_order(root);
    return 0;
}
