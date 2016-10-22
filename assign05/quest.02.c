#include <stdio.h>
#include <stdlib.h>

void pop_back(int *arr,int *capacity,int*size){
    (*size)--;
    if((*size) <= ((*capacity)/4) ){
        *capacity=(*capacity)/2;
        arr=(int*)realloc(arr,sizeof(int)*(*capacity));
    }
}


int main(){
    int capacity,size,calls;
    int *arr;
    scanf("%d%d",&capacity,&size);
    arr=(int*)malloc(sizeof(int)*capacity);
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&calls);
    
    for(int i=0;i<calls;i++){
        pop_back(arr,&capacity,&size);
        printf("capacity = %d; size = %d; elements = ",capacity,size);
        for(int j=0;j<size;j++)
            printf("%d ",arr[j]);
        puts("");
    }
    return 0;
}
