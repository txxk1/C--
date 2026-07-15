#include <bits/stdc++.h>

using namespace std;
const int M=200000;
int T,n,s[800005],S,now,ans;
char a[200005];
void solve(){
    S=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        s[i+M]=-2;
        s[-i+M]=-2;
        if(a[i]=='a') S++;
        else if(a[i]=='b') S--;
        else{
            cout <<a[i]<<endl;
            S-=M;
        }
    }
    if(S==0){
        cout <<0<<endl;
        return ;
    }
    s[M]=-1;
    now=0;
    ans=n;
    for(int i=1;i<=n;i++){
        if(a[i]=='a') now++;
        if(a[i]=='b') now--;
        s[now+M]=i;
        if(s[now+M-S]!=-2){
            if(now==S) ans=min(ans,i-max(0,s[M]));
            else ans=min(ans,i-s[now+M-S]);
        }
        //else if(now==S) ans=min(ans,i-max(0,s[M]));
    }
    //cout <<S<<endl;
    if(ans==n) cout <<-1<<endl;
    else cout <<ans<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}