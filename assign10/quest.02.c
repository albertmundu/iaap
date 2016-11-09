#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;}

struct edge {
    int vertex1;
    int vertex2;
    int weight;
};

struct node {
    struct edge*e;
    struct node*next;
};

struct edge*create_edge(int vertex1,int vertex2,int weight){
    struct edge*tmp=(struct edge*)malloc(sizeof(struct edge));
    tmp->vertex1=vertex1;
    tmp->vertex2=vertex2;
    tmp->weight=weight;
    return tmp;
}

struct node*create_node(struct edge*e){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->e=e;
    tmp->next=NULL;
    return tmp;
}

void insert_node(struct node**head,struct edge*e){
    if(*head==NULL){
        *head=create_node(e);
    }
    else {
        struct node*tmp=*head;
        for(;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=create_node(e);
    }
}   

void prt_list(struct node*head){
    for(;head!=NULL;head=head->next){
        printf("{<%d %d> [%d]} ",head->e->vertex1,head->e->vertex2,head->e->weight);
    }
    printf("\n");
}
int main(){
    struct node*head=NULL;
    int **mat=NULL,n;
    scanf("%d",&n);
    mat=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        mat[i]=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(mat[i][j]>0)
                insert_node(&head,create_edge(i+1,j+1,mat[i][j]));
        }
    }
    prt_list(head);
    return 0;
}
