#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	int rank;
	struct node*parent;
};

struct pool {
	struct node*item;
	struct pool*next;
};

struct pool * phead=NULL;

struct node*createnode(int data){
	struct node*tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->parent=NULL;
	tmp->rank=0;
	return tmp;
}

struct pool*createpool(struct node*item){
	struct pool*tmp=(struct pool*)malloc(sizeof(struct pool));
	tmp->item=item;
	tmp->next=NULL;
}
void insert(struct node*item){
	if(phead==NULL){
		phead=createpool(item);
	}
	else {
		struct pool*tmp=phead;
		for(;tmp->next!=NULL;tmp=tmp->next);
		tmp->next=createpool(item);
	}
}

void makeset(int data){
	struct node*tmp=createnode(data);
	tmp->parent=tmp;
	insert(tmp);
}

struct node*get(int data){
	struct pool*tmp=phead;
	for(;tmp!=NULL;tmp=tmp->next){
		if(tmp->item->data==data)
			return tmp->item;
	}
	return NULL;
}

struct node*findset(struct node*nd){
	struct node*p=nd->parent;
	if(p==nd)
		return p;
	nd->parent=findset(nd->parent);
	return nd->parent;
}
void unionset(int data1,int data2){
	struct node*n1=get(data1);
	struct node*n2=get(data2);
	struct node*p1=findset(n1);
	struct node*p2=findset(n2);

	if(p1->data==p2->data)
		return;
	if(p1->rank >= p2->rank){
		p1->rank=(p1->rank==p2->rank)?p1->rank+1:p1->rank;
		p2->parent=p1;
	}
	else
		p1->parent=p2;
}


void sort(int *arr,int n){
	for(int i=1;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(key<arr[j] && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

struct hash {
	int data;
	struct hash*next;
};
struct hash* createhashnode(int data){
	struct hash*tmp=(struct hash*)malloc(sizeof(struct hash));
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}
void inserthash(struct hash**hhead,int data){
	if(*hhead==NULL){
		*hhead=createhashnode(data);
	}
	else {
		int status=0;
		struct hash*tmp=*hhead,*prev=NULL;
		for(;tmp!=NULL;tmp=tmp->next){
			if(data==tmp->data){
				status=1;
				break;
			}
			prev=tmp;
		}
		if(status==0)
			prev->next=createhashnode(data);
	}
}


int main(){
	int n,*arr=NULL;
	struct hash*hhead=NULL;
	scanf("%d",&n);
	arr=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		makeset(arr[i]);
	}
	sort(arr,n);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j]==(arr[i]*arr[i])){
				unionset(arr[i],arr[j]);
			}
		}
	}
	for(int i=0;i<n;i++){
		inserthash(&hhead,findset(get(arr[i]))->data);
	}
	int count=0;
	for(struct hash*tmp=hhead;tmp!=NULL;tmp=tmp->next){
		count++;
	}
	printf("%d\n",count);
	return 0;
}
