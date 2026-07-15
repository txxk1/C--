#include <stdio.h>
#include <stdlib.h>
int n;
int main(){
    //system("chcp 936 > nul");
    scanf("%d",&n);
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            printf("%d 不是质数\n",n);
            return 0;
        }
    }
    printf("%d 是质数\n",n);
    return 0;
}