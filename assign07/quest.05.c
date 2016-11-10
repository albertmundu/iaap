#include <stdio.h>
#include <stdlib.h>

#define swap(a,b){int t=a;a=b;b=t;}


void heapify(int *arr,int n,int i,int *count){
    int left=2*i+1;
    int right=2*i+2;
    int max=i;
    if(left <= n && arr[left]>arr[min])
        max=left;
    if(right <= n && arr[right]>arr[min])
        max=right;
    if(max!=i){
        (*count)++;
        swap(arr[max],arr[i]);
        heapify(arr,n,max,count);
    }
}

void build_heap(int *arr,int n,int *count){
    for(int i=n/2;i>=0;i--){
        heapify(arr,n-1,i,count);
    }
}


int main(){
    int t,n,*arr=NULL;
    int count=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        build_heap(arr,n,&count);
        printf("%d\n",count);
        count=0;
        free(arr);
    }
}
