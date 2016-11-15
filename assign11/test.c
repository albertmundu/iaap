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