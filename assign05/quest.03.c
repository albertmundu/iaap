#include <stdio.h>
#include <stdlib.h>


void display(int *arr,int capacity, int size){
    printf("capacity = %d; size = %d; elements = ",capacity,size);
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    puts("");
}

void index(int *arr, int idx,int *size,int *capacity)
{
    for(int i=idx;i<*size;i++)
        arr[i]=arr[i+1];
    (*size)--;

    if(*size<=(*capacity/4)){
        *capacity=*capacity/2;
        arr=(int*)realloc(arr,sizeof(int)*(*capacity));
    }
}

void first_item_by_val(int *arr,int item, int *size, int *capacity){
    int idx;
    for(int i=0;i<*size;i++){
        if(arr[i]==item){
            idx=i;
            break;
        }
    }
    for(int i=idx;i<*size;i++)
        arr[i]=arr[i+1];
    (*size)--;

    if(*size <= (*capacity/4)){
        *capacity=*capacity/2;
        arr=(int *)realloc(arr,sizeof(int)*(*capacity));
    }
}

void delete_all_by_val(int *arr, int item, int *size, int * capacity){
    
    for(int i=0;i<*size;){
        if(arr[i]==item){
            for(int j=i;j<*size;j++){
                arr[j]=arr[j+1];
            }
            (*size)--;
            if(*size <= (*capacity/4)){
                *capacity=*capacity/2;
                arr=(int *)realloc(arr,sizeof(int)*(*capacity));
            }
        }

        if(arr[i]!=item)
            i++;
    }
}

int main(){
    int capacity,size,idx,first_value, all_value;
    scanf("%d%d",&capacity,&size);
    int *arr=(int *)malloc(sizeof(int)*capacity);

    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&idx);
    scanf("%d",&first_value);
    scanf("%d",&all_value);
    index(arr,idx,&size,&capacity);
    display(arr,capacity,size);
    first_item_by_val(arr,first_value,&size,&capacity);
    display(arr,capacity,size);
    delete_all_by_val(arr,all_value,&size,&capacity);
    display(arr,capacity,size);
    return 0;
}
