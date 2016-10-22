#include <stdio.h>


int main(){
    int n;
    scanf("%d",&n);
    
    int mat[n][n];
    int dsum=0;
    int msum=0,x=0;
    for(int i=0;i<n;i++){
        scanf("%d",&mat[i][i]);
        dsum+=mat[i][i];
    }
    
    for(;msum<dsum;){
        x++;
        msum=x*n*(n-1);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            mat[i][j]=x;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
    
        
    return 0;
}
