#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    int rank;
    struct node*parent;
};

struct pool {
    struct node*value;
    struct pool*left;
    struct pool*right;
};

struct pool*pool_head=NULL;

struct node*createnode(int data){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=data;
    tmp->rank=0;
    tmp->parent=NULL;
    return tmp;
}

struct pool *createpool(struct node*value){
    struct pool*tmp=(struct pool*)malloc(sizeof(struct pool));
    tmp->value=value;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

void insert(struct node*value){ //insert into pool
    if(pool_head==NULL){
        pool_head=createpool(value);
    }
    else {
        struct pool*child=pool_head,*parent=NULL;
        for(;child!=NULL;){
            parent=child;
            if(value->data <= child->value->data)
                child=child->left;
            else
                child=child->right;
        }
        if(value->data <= parent->value->data)
            parent->left=createpool(value);
        else
            parent->right=createpool(value);

    }
}

struct node*get(int data){
    struct pool*child=pool_head;
    for(;child!=NULL;){
        if(data == child->value->data)
            return child->value;
        if(data < child->value->data)
            child=child->left;
        else
            child=child->right;
    }
    return NULL;
}

void makeset(int data){
    struct node*tmp=createnode(data);
    tmp->parent=tmp;
    insert(tmp);
}
struct node*findset(struct node*nd){
    struct node*p=nd->parent;
    if(p==nd)
        return p;
    //nd->parent=findset(nd->parent);
    //return nd->parent;
    return findset(nd->parent);
}
int findsetbyelement(int data){
    return findset(get(data))->data;
}
int unionset(int data1,int data2){
    struct node*n1=get(data1);
    struct node*n2=get(data2);
    struct node*p1=findset(n1); //finding the representative of n1
    struct node*p2=findset(n2); //finding the representative of n2

    //main logic
    if(n1->parent!=n1 && n2->parent!=n2 && p1==p2)
    {
        return 1;
    }

    if(p1->data == p2->data) //already of the same set? return if yes
        return 0;
    if(p1->rank >= p2->rank){ //if not of the same set
        p1->rank=(p1->rank==p2->rank)?p1->rank+1:p1->rank;
        p2->parent=p1;
    }
    else{
        p1->parent=p2;
    }
    return 0;
}

struct hash {
    int data;
    struct hash*next;
};
int main(){
    int t,n;
    int **mat=NULL;
    int status=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mat=(int**)malloc(sizeof(int*)*n);
        for(int i=1;i<=n;i++) makeset(i);
        for(int i=0;i<n;i++){
            mat[i]=(int*)malloc(sizeof(int)*n);
            for(int j=0;j<n;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            if(status==1)
                break;
            for(int j=i+1;j<n;j++){
                if(mat[i][j]==1){
                    if(unionset(i+1,j+1)){
                        status=1;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
            free(mat[i]);
        free(mat);
        if(status==1)
        {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
        status=0;
        pool_head=NULL;

    }
}

/* sample input */
/*
2
5
0 1 1 1 1
1 0 1 1 0
1 1 0 0 1
1 1 0 0 0
1 0 1 0 0
6
0 1 0 0 0 0
1 0 1 0 0 0
0 1 0 1 0 0
0 0 1 0 1 0
0 0 0 1 0 1
0 0 0 0 1 0
*/
