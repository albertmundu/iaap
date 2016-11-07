#include <stdio.h>
#include <stdlib.h>

#define swap(a,b){int t=a;a=b;b=t;}


void heapify(int *arr,int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int min=i;
    if(left <= n && arr[left]<arr[min])
        min=left;
    if(right <= n && arr[right]<arr[min])
        min=right;
    if(min!=i){
        swap(arr[min],arr[i]);
        heapify(arr,n,min);
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

void delete_k(int *arr,int *n,int k){
    for(int i=0;i<k;i++){
        swap(arr[0],arr[*n-1]);
        (*n)--;
        heapify(arr,*n-1,0);
    }
}

int main(){
    int t,n,*arr=NULL,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        arr=(int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        build_heap(arr,n);
        prt_array(arr,n);
        delete_k(arr,&n,k);
        prt_array(arr,n);
        free(arr);
    }
}
/*
Input: (T, n, k, {x_i})
2
11
4
12 1 21 2 24 23 15 26 4 33 10
7 2
5 2 8 1 4 6 10
Output:
1 2 15 4 10 23 21 26 12 33 24
12 24 15 26 33 23 21
1 2 6 5 4 8 10
4 5 6 8 10
*/
