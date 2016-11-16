#include <stdio.h>
#include <stdlib.h>

typedef struct edge_s {
    int vertex1;
    int vertex2;
    int weight;
} edge_t;

typedef struct edges_node_s {
    struct edge_s*e;
    struct edges_node_s*next;
}edges_node_t;

typedef struct node_s {
    int vertex;
    int rank;
    struct node_s*parent;
} node_t;

typedef struct container_s {
    struct node_s*item;
    struct container_s*next;
}container_t;

node_t*createnode(int vertex){
    node_t*tmp=(node_t*)malloc(sizeof(node_t));
    tmp->vertex=vertex;
    tmp->rank=0;
    tmp->parent=tmp;
    return tmp;
}
container_t*create_container_node(node_t*node){
    container_t*tmp=(container_t*)malloc(sizeof(container_t));
    tmp->item=node;
    tmp->next=NULL;
    return tmp;
}
edges_node_t * create_edge_node(edge_t*e){
    edges_node_t*tmp=(edges_node_t*)malloc(sizeof(edges_node_t));
    tmp->e=e;
    tmp->next=NULL;
    return tmp;
}
void insert_edges(edges_node_t**head,edge_t*e){
    if(*head==NULL)
        *head=create_edge_node(e);
    else {
        edges_node_t*tmp=*head;
        for(;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=create_edge_node(e);
    }
}
void insert(container_t**head,node_t*node){
    if(*head==NULL)
        *head=create_container_node(node);
    else {
        container_t*tmp=*head;
        for(;tmp->next!=NULL;tmp=tmp->next);
        tmp->next=create_container_node(node);
    }
}

void makeset(container_t**head,int vertex){
    node_t*tmp=createnode(vertex);
    insert(head,tmp);
}

node_t* get(container_t*head,int vertex){
    for(;head!=NULL;head=head->next)
        if(head->item->vertex ==vertex)
            return head->item;
    return NULL;
}

node_t*findset(node_t*node){
    node_t*p=node->parent;
    if(p==node)
        return p;
    node->parent=findset(node->parent);
    return node->parent;
}
void unionset(container_t*head,int v1,int v2){
    node_t*n1=get(head,v1);
    node_t*n2=get(head,v2);
    node_t*p1=findset(n1);
    node_t*p2=findset(n2);
    if(p1==p2)
        return;
    if(p1->rank >= p2->rank){
        p1->rank=(p1->rank==p2->rank)?p1->rank+1:p1->rank;
        p2->parent=p1;
    }
    else
        p1->parent=p2;
}


void prt_edges(edge_t*edges,int n){
    for(int i=0;i<n;i++){
        printf("%d, ",edges[i].weight);
    }
    printf("\n");
}

int count_edges(int**mat,int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
            if(mat[i][j]>0)
                count++;
    }
    return count;
}

void push_edges(int**mat,int n,edge_t*edges){
    int edge_index=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++){
            if(mat[i][j]>0)
            {
                edges[edge_index].vertex1=i+1;
                edges[edge_index].vertex2=j+1;
                edges[edge_index].weight=mat[i][j];
                edge_index++;
            }
        }
    }
}

void sort(edge_t*edges,int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        edge_t key=edges[i];
        while(key.weight < edges[j].weight && j>=0){
            edges[j+1]=edges[j];
            j--;
        }
        edges[j+1]=key;
    }
}

edges_node_t* mst_kruskal(container_t*head,edge_t*edges, int edge_length){
    edges_node_t*result=NULL;
    sort(edges,edge_length);
    for(int i=0;i<edge_length;i++){
        node_t*rep1=findset(get(head,edges[i].vertex1));
        node_t*rep2=findset(get(head,edges[i].vertex2));
        if(rep1==rep2) continue;
        else {
            insert_edges(&result,&edges[i]);
            unionset(head,edges[i].vertex1,edges[i].vertex2);
        }
    }
    return result;
}
int main(){
    int n,**mat=NULL;
    edge_t *edges=NULL;
    container_t*chead=NULL;
    edges_node_t*result=NULL;
    scanf("%d",&n);
    mat=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) makeset(&chead,i+1);
    for(int i=0;i<n;i++){
        mat[i]=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    }
    int edge_length=count_edges(mat,n);
    edges=(edge_t*)malloc(sizeof(edge_t)*edge_length);
    push_edges(mat,n,edges);

    prt_edges(edges,edge_length);
    result=mst_kruskal(chead,edges,edge_length);

    for(edges_node_t*tmp=result;tmp!=NULL;tmp=tmp->next){
        printf("%d%d -> %d\n",tmp->e->vertex1,tmp->e->vertex2,tmp->e->weight);
    }
    printf("\n");
    return 0;
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