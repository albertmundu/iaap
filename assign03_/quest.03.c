#include <stdio.h>
#include <stdlib.h>
#define nl puts("")
#define swap(a,b){int t=a;a=b;b=t;}

void transpose(int (*)[],int*m,int*n);

int main(){
    int m,n;
<<<<<<< HEAD
    //int mat[10][10];
=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    scanf("%d%d",&m,&n);
    int mat[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);

    transpose(mat,&m,&n);

<<<<<<< HEAD
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++)
            printf("%2d ",mat[i][j]);
        nl;
   }
    
    
=======
    for(int i=0;i<m;i++){
       for(int j=0;j<n;j++)
            printf("%2d ",mat[i][j]);
        nl;
    }
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
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
