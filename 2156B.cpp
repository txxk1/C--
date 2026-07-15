#include <bits/stdc++.h>

using namespace std;
int T,n,q,f,s;
char ch[205];
void find(int x){
    int ans=0;
    if(s==1){
        cout <<x<<endl;
        return ;
    }
    while(x>0){
        int nowx=(x-f)/s;
        if(nowx<=0) break;
        x=nowx;
        ans+=n;
    }
    //cout <<" "<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(x==0) break;
        if(ch[i]=='A') x--;
        else x=x/2;
        ans++;
        
    }
    cout <<ans<<endl;
    return ;
}

void solve(){
    f=0;
    s=1;
    cin >>n>>q;
    for(int i=1;i<=n;i++){
        cin >>ch[i];
        if(ch[i]=='A'){
            f+=s;
        }
        else s=s*2;
    }
    for(int i=1;i<=q;i++){
        int x;
        cin >>x;
        find(x);
    }
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}