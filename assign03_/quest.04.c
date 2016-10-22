#include <stdio.h>
#define nl puts("")

void sort(int arr[],int n);
void alongRow(int (*)[],int n);
void alongCol(int (*)[],int n);
void uniqValues(int (*)[],int n);

int main(){
    int n;
    scanf("%d",&n);
    int mat[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    
<<<<<<< HEAD
    
=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    puts("Along rows: ");
    alongRow(mat,n);

    puts("Along columns:");
    alongCol(mat,n);

    puts("Matrix:");
    uniqValues(mat,n);

    return 0;
}


void sort(int arr[],int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(key<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void alongRow(int (*mat)[],int n){
    int (*tmp)[n]=mat;
    
    int aux[n][n],prev;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            aux[i][j]=tmp[i][j];


    for(int i=0;i<n;i++)
    {
        sort(aux[i],n);
        for(int j=0;j<n;j++){
            if(j==0)
                printf("%2d ",aux[i][j]);
            else if(prev!=aux[i][j])
                printf("%2d ",aux[i][j]);
            prev=aux[i][j];
        }
        nl;
    }
}

void alongCol(int (*mat)[],int n){
    int (*tmp)[n]=mat;
    
    int aux[n][n],prev;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            aux[i][j]=tmp[j][i];
<<<<<<< HEAD

=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    
    for(int i=0;i<n;i++)
    {
        sort(aux[i],n);
        prev=aux[i][0];
        for(int j=0;j<n;j++){
            if(j==0)
                printf("%2d ",aux[i][j]);
            else if(prev!=aux[i][j])
                printf("%2d ",aux[i][j]);
            prev=aux[i][j];
        }
        nl;
    }
}


void uniqValues(int (*mat)[],int n){
    
    int (*tmp)[n]=mat;
    
    int aux[n*n],aindex=0,prev;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            aux[aindex++]=tmp[j][i];
    sort(aux,n*n);

    for(int i=0;i<n*n;i++){
        if(i==0)
            printf("%d ",aux[i]);
        else if(prev!=aux[i])
            printf("%d ",aux[i]);
        prev=aux[i];

    }
<<<<<<< HEAD

=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
}
