#include <stdio.h>
#include <stdlib.h>

#define swap(a,b){int t=a;a=b;b=t;}


void heapify(int *arr,int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int max=i;
    if(left <= n && arr[left]>arr[max])
        max=left;
    if(right <= n && arr[right]>arr[max])
        max=right;
    if(max!=i){
        swap(arr[max],arr[i]);
        heapify(arr,n,max);
    }
}

void build_heap(int *arr,int n){
    for(int i=n/2;i>=0;i--){
        heapify(arr,n-1,i);
    }
}

void prt_array(int *arr,int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int n,*arr=NULL;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    build_heap(arr,n);
    prt_array(arr,n);
    free(arr);
    return 0;
}
