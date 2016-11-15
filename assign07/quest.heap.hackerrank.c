#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;} 

void heapify(int *arr,int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int min=i;
    if(left <= n && arr[left]<arr[min])
        min=left;
    if(right <=n && arr[right]<arr[min])
        min=right;
    if(min!=i){
        swap(arr[min],arr[i]);
        heapify(arr,n,min);
    }
}

int find(int *arr,int n,int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k)
            return i;
    }
    return -1;
}

void delete(int *arr,int *l,int k){
    int index=find(arr,*l,k);
    if(index==-1)
        return;
    (*l)--;
    arr[index]=arr[*l];
    heapify(arr,*l-1,index);
}

void insert(int*arr,int *l,int k){
    int i=(*l);
    arr[i]=k;
    int p=(i-1)/2;
    while(arr[p]>arr[i] && p>=0){
        swap(arr[p],arr[i]);
        i=p;
        p=(i-1)/2;
    }
    (*l)++;
}

int main(){
    int Q,*arr=NULL,choice,key,l;
    scanf("%d",&Q);
    arr=(int*)malloc(sizeof(int)*Q);
    l=0;
    while(Q--){
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%d",&key);
                insert(arr,&l,key);
                break;
            case 2:
                scanf("%d",&key);
                delete(arr,&l,key);
                break;
            case 3:
                printf("%d\n",arr[0]);
                break;
        }
    }
    return 0;
}