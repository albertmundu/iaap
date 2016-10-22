#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int mat[n][n];
    int sumRow[10]={0};
    int sumCol[10]={0};

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            sumRow[i]+=mat[i][j];
            sumCol[i]+=mat[j][i];
        }

    int exit_loop=0;
    for(int i=0;i<n && exit_loop==0;i++){
        for(int j=0;j<n;j++){
            if(sumRow[i]==sumCol[j]){
                printf("Row: %d\n",i+1);
                printf("Column: %d\n",j+1);
                exit_loop=1;
                break;
            }
        }
    }

    return 0;
}
