#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;}

void heapify(int *arr,int n, int i){
    int left=2*i;
    int right=2*i+1;
    int max=i;
    if(left<=n && arr[left]>arr[max])
        max=left;
    if(right<=n && arr[right]>arr[max])
        max=right;
    if(max!=i){
        swap(arr[max],arr[i]);
        heapify(arr,n,max);
    }
}
void build_heap(int *arr,int n){
    for(int i=n/2;i>=1;i--)
        heapify(arr,n,i);
}
void heap_sort(int *arr,int n){
    build_heap(arr,n);
    for(int i=n;i>=2;i--){
        swap(arr[1],arr[i]);
        heapify(arr,i-1,1);
    }
}
void prt_array(int *arr,int n){
    for(int i=1;i<=n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int *arr=NULL,t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        arr=(int*)malloc(sizeof(int)*(n+1));
        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        heap_sort(arr,n);
        prt_array(arr,n);
        free(arr);
    }
}
/*
Input: (T, n_i, {x_i})
2 6
12 11 20 5 16 7
8
15 24 16 22 5 20 40 8
Output:
5 7 11 12 16 20
5 8 15 16 20 22 24 40
*/
