#include <stdio.h>
<<<<<<< HEAD


int main(){
    int n;
    scanf("%d",&n);
    
=======
int main(){
    int n;
    scanf("%d",&n);
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    int mat[n][n];
    int dsum=0;
    int msum=0,x=0;
    for(int i=0;i<n;i++){
        scanf("%d",&mat[i][i]);
        dsum+=mat[i][i];
    }
<<<<<<< HEAD
    
=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    for(;msum<dsum;){
        x++;
        msum=x*n*(n-1);
    }
<<<<<<< HEAD
    
=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            mat[i][j]=x;
        }
    }
<<<<<<< HEAD

=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%2d ",mat[i][j]);
        }
        printf("\n");
    }
<<<<<<< HEAD
    
        
=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    return 0;
}
