#include <stdio.h>
#include <stdlib.h>

void display(int *arr,int c,int n){
    printf("capacity =%d; size =%d; elements = ",c,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    puts("");
}

int main(){
    int n;
    int capacity=0,size=0;
    scanf("%d",&n);

    int *a;

    for(int i=0;i<n;i++){
        if(size<1){
            capacity=1;
            a=(int*)malloc(sizeof(int)*capacity);
            scanf("%d",&a[i]);
        }
        else if(capacity==size){
            capacity=2*size;
            a=(int*)realloc(a,sizeof(int)*capacity);
            scanf("%d",&a[i]);
        }
        else{
            scanf("%d",&a[i]);
        }
        size+=1;
        display(a,capacity,size);
        //size+=1;
    }
}
