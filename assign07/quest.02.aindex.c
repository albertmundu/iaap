#include <stdio.h>
#include <stdlib.h>
#define swap(a,b){int t=a;a=b;b=t;}

void heapify(int *arr,int n,int i){
    int left=2*i;
    int right=2*i+1;
    int max=i;
    if(left <=n && arr[left] > arr[max])
        max=left;
    if(right <=n && arr[right] > arr[max])
        max=right;
    if(max!=i){
        swap(arr[max],arr[i]);
        heapify(arr,n,max);
    }
}

int find(int *arr,int n,int k){
    for(int i=1;i<n;i++){
        if(arr[i]==k)
            return i;
    }
    return -1;
}

void delete(int *arr,int *n,int data){
    int index=find(arr,*n,data);
    if(index==-1){
        printf("%d not found\n",data);
        return;
    }
    arr[index]=arr[*n-1];
    (*n)--;
    arr=(int*)realloc(arr, *n*sizeof(int));
    heapify(arr,*n,index);
    printf("deleted\n");
}
void insert(int *arr,int *n,int data){
    arr[*n-1]=data;
    int i=*n-1;
    int parent=i/2;
    while(arr[parent]<arr[i] && parent>=1){
        swap(arr[parent],arr[i]);
        i=parent;
        parent=i/2;
    }
    printf("inserted\n");
}
void display(int *arr,int n){
    for(int i=1;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void menu(int *arr,int *n){
    int choice,data;
    while(1){
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                scanf("%d",&data);
                if(*n==1){
                    arr=(int*)malloc(sizeof(int)*(*n+1));
                    (*n)++;
                }
                else{
                    (*n)++;
                    arr=(int*)realloc(arr,(*n+1)*sizeof(int));
                }
                insert(arr,n,data);
            break;
            case 2:
                scanf("%d",&data);
                delete(arr,n,data);
            break;
            case 3:
                display(arr,*n);
            break;
            case 4:
                return;
            break;
        }
    }
}

int main(){
    int *arr=NULL;
    int n=1;
    menu(arr,&n);
    return 0;
}

/*
Input: (n, x_i)
1 30
1 50
1 70
2 10
2 50
1 100
3 4
Output:
inserted
inserted
inserted
10 not found
deleted
100 30 70
*/
