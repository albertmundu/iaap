#include <stdio.h>
#include <stdlib.h>

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
    if(root==NULL) root=createnode(data);
    else {
        if(data <= root->data)
            root->left=insert(root->left,data);
        else if(data > root->data)
            root->right=insert(root->right,data);
    }
    return root;
}

/**begin queue implementation**/
struct qnode {
    struct node*item;
    struct qnode*next;
};

struct qnode*createqnode(struct node*item){
    struct qnode*tmp=(struct qnode*)malloc(sizeof(struct node));
    tmp->item=item;
    tmp->next=NULL;
    return tmp;
}
int isempty(struct qnode*qhead){
    if(qhead==NULL)
        return 1;
    return 0;
}
struct qnode*front(struct qnode*qhead){
    return qhead;
}
void enqueue(struct qnode**qhead,struct qnode**qtail,struct node*item){
    if(isempty(*qhead)) *qhead=*qtail=createqnode(item);
    else{
        (*qtail)->next=createqnode(item);
        *qtail=(*qtail)->next;
    }
}
void dequeue(struct qnode**qhead){
    if(isempty(*qhead)) return;
    struct qnode*tmp=*qhead;
    *qhead=(*qhead)->next;
    free(tmp);
}
/**end queue implementation**/

void bfs(struct node*root){
    if(root==NULL) return;
    struct qnode*qhead=NULL,*qtail=NULL;
    enqueue(&qhead, &qtail, root);
    while(!isempty(qhead)){
        struct node*root=front(qhead)->item;
        printf("%d ",root->data);
        if(root->left!=NULL) enqueue(&qhead,&qtail,root->left);
        if(root->right!=NULL) enqueue(&qhead,&qtail,root->right);
        dequeue(&qhead);
    }
    printf("\n");
}


int main(){
    struct node*root=NULL;
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
    bfs(root);
    return 0;
}
