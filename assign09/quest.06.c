#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    int rank;
    struct node*parent;
};

struct pool {
    struct node*value;
    struct pool*next;
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
    tmp->next=NULL;
    return tmp;
}

void insert(struct node*value){ //insert into pool
    if(pool_head==NULL){
        pool_head=createpool(value);
    }
    else {
        struct pool*tmp=pool_head;
        for(;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=createpool(value);
    }
}

struct node*get(int data){
    struct pool*tmp=pool_head;
    for(;tmp!=NULL;tmp=tmp->next){
        if(tmp->value->data==data)
            return tmp->value;
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
    nd->parent=findset(nd->parent);
    return nd->parent;
}
int findsetbyelement(int data){
    return findset(get(data))->data;
}
void unionset(int data1,int data2){
    struct node*n1=get(data1);
    struct node*n2=get(data2);
    struct node*p1=findset(n1); //finding the representative of n1
    struct node*p2=findset(n2); //finding the representative of n2

    if(p1->data == p2->data) //already of the same set? return if yes
        return;
    if(p1->rank >= p2->rank){ //if not of the same set
        p1->rank=(p1->rank==p2->rank)?p1->rank+1:p1->rank;
        p2->parent=p1;
    }
    else{
        p1->parent=p2;
    }
}

struct hash {
    int data;
    struct hash*next;
};
int main(){
    int t,n;
    int **mat=NULL;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mat=(int**)malloc(sizeof(int*)*n);
        for(int i=1;i<=n;i++) makeset(i);
        for(int i=0;i<n;i++){
            mat[i]=(int*)malloc(sizeof(int)*n);
            for(int j=0;j<n;j++){
                scanf("%d",&mat[i][j]);
                if(mat[i][j]==1)
                    unionset(i+1,j+1);
            }
        }
        int rep=findsetbyelement(1),connected=1;

        for(int i=1;i<=n;i++)
        {
            if(rep!=findsetbyelement(i)){
                connected=0;
                break;
            }
        }
        if(connected)
            printf("Connected\n");
        else
            printf("Disconnected\n");

    }
}

/* sample input */
/*
2
6
0 1 1 1 0 0
1 0 1 0 1 0
1 1 1 1 0 0
0 1 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
6
0 1 1 1 0 0
1 0 1 0 1 1
1 1 1 1 0 0
0 1 0 1 0 0
0 1 0 0 0 0
0 1 0 0 0 1
*/
