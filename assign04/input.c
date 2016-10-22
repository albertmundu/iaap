#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int k,data;
    char buffer[100];
    fgets(buffer,100,stdin);


    char *p=strtok(buffer," abcdefghijklmnopqrstuvwxyz\n=");
    sscanf(p,"%d",&k);
    printf("%d\n",k);

    fgets(buffer,100,stdin);
    
    char *pch;
    pch=strtok(buffer," ->NULL");
    for(;pch!=NULL;)
    {
        sscanf(pch,"%d",&data);
        printf("%d\n",data);
        pch=strtok(NULL," ->NULL\n");
    }
    

    return 0;
}
