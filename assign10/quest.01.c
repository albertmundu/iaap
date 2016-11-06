#include <stdio.h>
#include <stdlib.h>

struct edge {
    int weight;
    int vertex1;
    int vertex2;
};

struct listnode { //for storing the edges
    struct edge*e;
    struct listnode*next;
};

struct node { //for disjoint set
    int vertex;
    int rank;
    struct node*parent;
};

struct container { //disjoint set container
    struct node*item;
    struct container*next;
};

struct edge*newedge(int w,int v1,int v2);
struct listnode*newlistnode(struct edge*e);
void insert(struct listnode **head,struct edge*e);
struct container * create_container_node(struct node*item);
void insert_into_container(struct container**head,struct node*item);
struct node*get(struct container*head,int vertex);
void makeset(struct container**chead,int vertex);
struct node*findset(struct node*item);
void unionset(struct container*head,int vertex1,int vertex2);
struct listnode*mst_kruskal(struct container*head,struct listnode**lhead);
void sorted_insert(struct listnode**head,struct listnode*keynode);
void sort(struct listnode**lhead);
void set_matrix(int **mat,int n,struct listnode*head);
void free_all(int**mat,int n,struct listnode**lhead,struct listnode**rhead,struct container**chead);



struct edge* newedge(int w,int v1,int v2){
    struct edge*tmp=(struct edge*)malloc(sizeof(struct node));
    tmp->weight=w;
    tmp->vertex1=v1;
    tmp->vertex2=v2;
    return tmp;
}
struct listnode*newlistnode(struct edge*e){
    struct listnode*tmp=(struct listnode*)malloc(sizeof(struct listnode));
    tmp->e=e;
    tmp->next=NULL;
    return tmp;
}
 void insert(struct listnode **head,struct edge*e){
     if(*head==NULL){
         *head=newlistnode(e);
     }
     else {
         struct listnode*tmp=*head;
         for(;tmp->next!=NULL;tmp=tmp->next);
         tmp->next=newlistnode(e);
     }
 }

/*data structure for disjoint sets*/
struct container * create_container_node(struct node*item){
    struct container*tmp=(struct container*)malloc(sizeof(struct container));
    tmp->item=item;
    tmp->next=NULL;
    return tmp;
}
void insert_into_container(struct container**head,struct node*item){
    if(*head==NULL) *head=create_container_node(item);
    else{
        struct container*tmp=*head;
        for(;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=create_container_node(item);
    }
}

struct node*get(struct container*head,int vertex){
    for(;head!=NULL;head=head->next){
        if(head->item->vertex==vertex)
            return head->item;
    }
    return NULL;
}

void makeset(struct container**chead,int vertex){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->vertex=vertex;
    tmp->rank=0;
    tmp->parent=tmp;
    insert_into_container(chead,tmp);
}

struct node*findset(struct node*item){
    struct node*p=item->parent;
    if(p==item)
        return p;
    item->parent=findset(item->parent);
    return item->parent;
}

void unionset(struct container*head,int v1,int v2){
    struct node*n1=get(head,v1);
    struct node*n2=get(head,v2);
    struct node*rep1=findset(n1);
    struct node*rep2=findset(n2);
    if(rep1==rep2)
        return;
    if(rep1->rank >= rep2->rank){
        rep1->rank=(rep1->rank==rep2->rank)?rep1->rank+1:rep1->rank;
        rep2->parent=rep1;
    }
    else{
        rep1->parent=rep2;
    }
}

struct listnode*mst_kruskal(struct container*head,struct listnode**lhead){
    sort(lhead);
    struct listnode*result_head=NULL;
    for(struct listnode*edge_node=*lhead;edge_node!=NULL;edge_node=edge_node->next){
        struct node*rep1=findset(get(head,edge_node->e->vertex1));
        struct node*rep2=findset(get(head,edge_node->e->vertex2));
        if(rep1==rep2)
            continue;
        else{
            insert(&result_head,newedge(edge_node->e->weight,edge_node->e->vertex1,edge_node->e->vertex2));
            unionset(head,edge_node->e->vertex1,edge_node->e->vertex2);
        }
    }
    return result_head;
}

void sorted_insert(struct listnode**head,struct listnode*keynode){
    struct listnode*current=NULL;
    if(*head == NULL || (*head)->e->weight >= keynode->e->weight){
        keynode->next=*head;
        *head=keynode;
    }
    else{
        current=*head;
        while(current->next!=NULL && current->next->e->weight < keynode->e->weight)
            current=current->next;
        keynode->next=current->next;
        current->next=keynode;
    }
}

 void sort(struct listnode**lhead){
     struct listnode*sorted=NULL,*current=*lhead;
     for(;current!=NULL;){
        struct listnode*next=current->next;
        sorted_insert(&sorted,current);
        current=next;
     }
     *lhead=sorted;
 }

void set_matrix(int **mat,int n,struct listnode*head){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j]=0;
        }
    }
    for(;head!=NULL;head=head->next){
        mat[head->e->vertex1-1][head->e->vertex2-1]=mat[head->e->vertex2-1][head->e->vertex1-1]=head->e->weight;
    }
}

void free_all(int**mat,int n,struct listnode**lhead,struct listnode**rhead,struct container**chead){
    for(int i=0;i<n;i++)
        free(mat[i]);
    free(mat);
    for(struct listnode*tmp=*lhead,*prev=NULL;tmp!=NULL;){
        prev=tmp;
        free(prev->e);
        tmp=tmp->next;
        free(prev);
    }
    for(struct listnode*tmp=*rhead,*prev=NULL;tmp!=NULL;){
        prev=tmp;
        free(prev->e);
        tmp=tmp->next;
        free(prev);
    }
    for(struct container*tmp=*chead,*prev=NULL;tmp!=NULL;){
        prev=tmp;
        free(prev->item);
        tmp=tmp->next;
        free(prev);
    }
}

int main(){
    struct listnode*lhead=NULL,*rhead=NULL;
    struct container*chead=NULL;
    int n;
    int **mat;
    scanf("%d",&n);
    mat=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        makeset(&chead,i+1);
        mat[i]=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(mat[i][j]>0){
                insert(&lhead,newedge(mat[i][j],i+1,j+1));
            }
        }
    }

    rhead=mst_kruskal(chead,&lhead);
    set_matrix(mat,n,rhead);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    free_all(mat,n,&lhead,&rhead,&chead);
}
/*
Sample Input
7
0 0 7 5 0 0 0
0 0 8 0 5 0 0
7 8 0 9 7 0 0
5 0 9 0 15 6 0
0 5 7 15 0 8 9
0 0 0 6 8 0 11
0 0 0 0 9 11 0

Sample Output
0 0 7 5 0 0 0
0 0 0 0 5 0 0
7 0 0 0 7 0 0
5 0 0 0 0 6 0
0 5 7 0 0 0 9
0 0 0 6 0 0 0
0 0 0 0 9 0 0
*/
