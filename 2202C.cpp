#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[300005];
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
    int ans=0;
    cin >>n;
    map<int,int> t;
    for(int i=1;i<=n;i++) cin >>a[i];
    a[n+1]=0;
    t[0]=0;
    for(int i=1;i<=n;i++){
        if(a[i+1]==a[i]+1){
            int now=1;
            t[1]=1;
            /*
            while(a[i+now]==a[i]+now&&now<=n){
                
                now++;
            }*/
            while(t[a[i+now]-a[i]]==1&&i+now<=n+1){
                t[a[i+now]-a[i]+1]=1;
                now++;
            }
            for(int i=1;i<=now+1;i++) t[i]=0;
            i=i+now-1;
        }
        ans++;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}