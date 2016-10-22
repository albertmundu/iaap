#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int ch;
    struct node*next;
};

struct node*createnode(int ch){
    struct node*tmp=(struct node*)malloc(sizeof(struct node));
    tmp->ch=ch;
    tmp->next=NULL;
    return tmp;
}

void insert(struct node**head,int ch){
    struct node*newnode=createnode(ch);
    if(*head==NULL){
        *head=newnode;
    }
    else {
        struct node*tmp=*head;;
        for(;tmp->next!=NULL;tmp=tmp->next);
            tmp->next=newnode;
    }
}

void prt_unique(struct node**head){
    for(int i=0;i<26;i++){
        if(head[i]!=NULL)
            printf("%c ",head[i]->ch);
    }
    printf("\n");
}

int main(){
    int n,len;
    scanf("%d",&n);
    char str[100];

    struct node *table[26]={NULL};
    for(int i=0;i<n;i++){
        scanf("%s",str);
        len=strlen(str);
        for(int j=0;j<len;j++){
            insert(&table[(str[j]-97)%26],str[j]);
        }
        prt_unique(table);
        for(int j=0;j<26;j++)
            table[j]=NULL;
    }

}
