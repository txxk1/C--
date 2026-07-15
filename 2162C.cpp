#include <bits/stdc++.h>

using namespace std;
int T,a,b,now,ans[1005],cnt;
void solve(){
    cnt=0;
    cin >>a>>b;
    for(int i=0;i<31;i++){
        if((a<(1<<i))&&(b>=(1<<i))){
            cout <<-1<<endl;
            return ;
        }
        else if((a<(1<<i))&&(b<(1<<i))){
            now=i;
        }
    }
    for(int i=0;i<now;i++){
        int x=(a&(1<<i)),y=(b&(1<<i));
        if(x!=y) ans[++cnt]=(1<<i);
    }
    cout <<cnt<<endl;
    if(cnt==0) return ;
    for(int i=1;i<=cnt;i++){
        cout <<ans[i]<<" ";
    }
    cout <<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}