#include <stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    int mat[n][n],sum=0,count=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);

    for(int i=0;i<n;i++){
        if(i==0){
            sum=mat[i][i+1]+mat[i+1][i];
        }
        else if(i==n-1){
            sum=mat[i][i-1]+mat[i-1][i];
        }
        else{
            sum=mat[i][i-1]+mat[i][i+1]+mat[i-1][i]+mat[i+1][i];
        }
        
        if(sum==mat[i][i]){
            count++;
        }
    }

    if(count==n){
        puts("yes");
    }
    else{
        puts("no");
    }
    return 0;
}
