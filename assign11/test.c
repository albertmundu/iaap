#include <stdio.h>


int max(int a,int b){
    return (a>b)?1:0;
}

int main(){
    int A=0;
    int B=0;
    int a0; 
    int a1; 
    int a2; 
    scanf("%d %d %d",&a0,&a1,&a2);
    int b0; 
    int b1; 
    int b2; 
    scanf("%d %d %d",&b0,&b1,&b2);
    if(max(a0,b0))
        A++;
    else if(max(b0,a0))
        B++;
    
    if(max(a1,b1))
        A++;
    else if(max(b1,a1))
        B++;

    if(max(a2,b2))
        A++;
    else if(max(b2,a2))
        B++;

    printf("%d %d\n",A,B);
    return 0;
}