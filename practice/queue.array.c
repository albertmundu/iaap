#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 10
int isempty(int f,int r){
    if(f==-1 && r==-1)
        return 1;
    return 0;
}

int isfull(int f,int r){
    // if(r==(Q_SIZE-1))
        // return 1;
    if((r+1)%Q_SIZE==f) //circular
        return 1;
    return 0;
}
int front(int*arr,int f){
    if(f>=0)
        return arr[f];
    return -1;
}

void enqueue(int *arr,int*f,int*r,int item){
    if(isempty(*f,*r)){
        *f=0;
        *r=0;
    }
    else if(isfull(*f,*r))
        return;
    else
        *r=(*r+1)%Q_SIZE;
    arr[*r]=item;
}
void dequeue(int *arr,int *f, int *r){
    if(isempty(*f,*r))
        return;
    else if(f==r)
        f=r=-1;
    // else (*f)++;
    else *f=(*f+1)%Q_SIZE; 
    //return arr[(*f)++];
}
void prt_queue(int*arr,int f,int r){
    for(int i=f;i<=r;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int *arr=NULL;
    int f=-1,r=-1;
    arr=(int*)malloc(sizeof(int)*Q_SIZE);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    prt_queue(arr,f,r);
    dequeue(arr, &f, &r);
    dequeue(arr, &f, &r);
    dequeue(arr, &f, &r);
    dequeue(arr, &f, &r);
    prt_queue(arr, f, r);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    prt_queue(arr, f, r);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    enqueue(arr, &f, &r, 78);
    return 0;
}
