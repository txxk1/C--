#include <iostream>
using namespace std;
int x,y,m,n,o,p;

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