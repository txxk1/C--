#include <iostream>
using namespace std;
int S,ans;
void dfs(int x,int now,int step){
    if(x<0) return ;
    if(x==0){
        ans=min(ans,step);
        return ;
    }
    for(int i=2;i<=9;i++){
        if((x-1)%i==0) dfs((x-1)/i,i,step+1);
    }
}
int main(){
    ans=1e8;
    cin >>S;
    for(int i=3;i*i<=S;i++){
        if(S%i==0){
            dfs(i,1,0);
        }
    }  
    dfs(S,1,0);
    if(ans!=1e8) cout <<ans;
    else cout <<-1;
    return 0;
}