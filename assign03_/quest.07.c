#include <stdio.h>
#include <math.h>
#include <string.h>

<<<<<<< HEAD

=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
void check(char (*)[],int n);

int main(){
    int n;
    scanf("%d",&n);
    char str[n][30];
    for(int i=0;i<n;i++)
        scanf("%s",str[i]);
    
    check(str,n);
    
}

void check(char (*str)[],int n){
    char (*tmp)[30]=str;
    int len;
    int count;
    for(int i=0;i<n;i++){
        len=strlen(tmp[i]);
        count=0;
        for(int j=0;j<(int)ceil(len/2.0);j++){
            if(tmp[i][j]!=tmp[i][len-1-j]){
                puts("no");
                break;
            }
            else count++;
        }
        if(count==(int)ceil(len/2.0))
            puts("yes");
    }
}
