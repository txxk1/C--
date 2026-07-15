#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,pos[200005];
char a[200005];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
void solve(){
    int cnt=0,ans=0;
    cin >>n;
    cin >>a;
    for(int i=0;i<n;i++){
        if(a[i]=='1') pos[++cnt]=i+1;
    }
    if(n==1){
        cout <<1<<endl;
        return ;
    }
    if(cnt==0){
        for(int i=2;i<=n;i+=3){
            if(i==n-2) ans++;
            ans++;
        }
        cout <<ans<<endl;
        return ;
    }
    if(pos[1]==3) ans++;
    for(int i=pos[1]-3;i>=1;i-=3){
        //cout <<i<<endl;
        if(i==3) ans++;
        ans++;
    }
    for(int i=2;i<=cnt;i++){
        for(int j=pos[i-1]+3;j<=pos[i]-1;j+=3){
            //cout <<j<<endl;
            ans++;
        }
        // 1001001001 0001
    }
    // pos[cnt]+1 n n-pos[cnt]
    if(pos[cnt]==n-2) ans++;
    for(int i=pos[cnt]+3;i<=n;i+=3){
        //cout <<i<<endl;
        if(i==n-2) ans++;
        ans++;
    }
    cout <<ans+cnt<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}