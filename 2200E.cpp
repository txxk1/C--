#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y;
int a[200005],cnt[100005],ma[100005],mi[100005];
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
    int flag=0;
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        int x=a[i],sum=0;
        mi[i]=x;
        ma[i]=0;
        for(int j=2;j*j<=x;j++){
            while(x%j==0){
                sum++;
                x=x/j;
                mi[i]=min(mi[i],j);
                ma[i]=max(ma[i],j);
            }
        }
        if(x!=1){
            ma[i]=max(ma[i],x);
            mi[i]=min(mi[i],x);
        }
        if(ma[i]==0) ma[i]=a[i];
    }
    for(int i=2;i<=n;i++){
        if(mi[i]<ma[i-1]) flag=1;
    }
    if(flag==0) cout <<"Bob"<<endl;
    else cout <<"Alice"<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}