#include <bits/stdc++.h>

using namespace std;
int T,n,q,a[250005],s[250005],a1[250005],a2[250005];
void solve(){
    cin >>n>>q;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]==1) a1[i]=a1[i-1]+1,a2[i]=a2[i-1];
        if(a[i]==0) a1[i]=a1[i-1],a2[i]=a2[i-1]+1;
        if(a[i]!=a[i-1]) s[i]=s[i-1]+1;
        else s[i]=s[i-1];
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin >>l>>r;
        if((r-l+1)%3!=0||(a2[r]-a2[l-1])%3!=0){
            cout <<-1<<endl;
        }
        else{
            int x=(r-l+1)/3;
            if(s[r]-s[l+1]==r-l-1) cout <<x+1<<endl;
            else cout <<x<<endl;
        }
    }
    for(int i=1;i<=n;i++) a1[i]=a2[i]=0;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}