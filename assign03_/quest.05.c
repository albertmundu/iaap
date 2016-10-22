#include <stdio.h>
#include <string.h>
#define nl puts("")
<<<<<<< HEAD

void sort(char (*arr)[],int n);


int main(){

=======
void sort(char (*arr)[],int n);

int main(){
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    int n;
    scanf("%d",&n);
    char name[n][30];
    char prev[30];
<<<<<<< HEAD

=======
>>>>>>> d3d5275e4c1913c3933f231cc81a12f9ec79079d
    for(int i=0;i<n;i++){
        scanf("%s",name[i]);
    }
    
    sort(name,n);
    
    puts("Sorted:");
    for(int i=0;i<n;i++)
        printf("%s ",name[i]);
    
    nl;
    puts("Unique:");

    for(int i=0;i<n;i++){
        if(i==0){
            printf("%s ",name[i]);
        }
        else if(strcmp(prev,name[i])!=0)
            printf("%s ",name[i]);
        strcpy(prev,name[i]);
    }
    nl;
    return 0;
}

void sort(char (*arr)[],int n){
    char (*tmp)[30]=arr;
    char key[30];
    int j;
    
    for(int i=1;i<n;i++){
        strcpy(key,tmp[i]);
        j=i-1;
        while(strcmp(key,tmp[j]) < 0 && j>=0){
            strcpy(tmp[j+1],tmp[j]);
            j--;
        }
        strcpy(tmp[j+1],key);
    }
}
