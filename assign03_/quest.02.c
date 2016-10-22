#include <stdio.h>

<<<<<<< HEAD

int main(){
    int n;
    scanf("%d",&n);

    int mat[n][n];
=======
int main(){
    int n;
    scanf("%d",&n);
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    int sum=0,psum=0;
    int mindex=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    }

    for(int i=0;i<n;i++){
        if(i==0)
            sum=mat[i+1][i+1]+mat[i][i+1]+mat[i+1][i];
        else if(i==n-1)
            sum=mat[i-1][i-1]+mat[i][i-1]+mat[i-1][i];
        else
            sum=mat[i-1][i-1]+mat[i+1][i+1]+mat[i-1][i]+mat[i+1][i]+mat[i][i-1]+mat[i][i+1]+mat[i+1][i-1]+mat[i-1][i+1];
        printf("%d: %d\n",mat[i][i],sum);

        if(psum<sum){
            psum=sum;
            mindex=i;
        }
    }
    printf("index: %d",mindex+1);
<<<<<<< HEAD

=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    return 0;
}
