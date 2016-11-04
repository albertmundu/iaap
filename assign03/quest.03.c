#include <stdio.h>
#include <stdlib.h>
#define nl puts("")
#define swap(a,b){int t=a;a=b;b=t;}

void transpose(int (*)[],int*m,int*n);

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int mat[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);

    transpose(mat,&m,&n);

   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++)
            printf("%2d ",mat[i][j]);
        nl;
   }
    
    
    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++)
            printf("%2d ",mat[i][j]);
        nl;
    }
}

void transpose(int (*arr)[], int *m, int *n){
    int (*temp)[*n]=arr;
    int tarr[*n][*m];

    for(int i=0;i<*n;i++)
        for(int j=0;j<*m;j++)
            tarr[i][j]=temp[j][i];
        
    for(int i=0;i<*n;i++)
        for(int j=0;j<*m;j++)
            temp[i][j]=tarr[i][j];

    swap(*m,*n);
}
