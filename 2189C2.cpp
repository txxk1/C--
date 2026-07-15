#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[200005],lg[200005];
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
    n=read();
    if(n==(1<<lg[n])){
        cout <<-1<<endl;
        return ;
    }
    if(n%2==0){
        a[1]=n;
        for(int i=2;i<=n-2;i+=2){
            a[i]=i+1;
            a[i+1]=i;
        }
        a[n]=1;
        int x=n-(1<<lg[n]);
        swap(a[1],a[x]);
    }
    else{
        a[1]=n-1;
        for(int i=2;i<=n-3;i+=2){
            a[i]=i+1;
            a[i+1]=i;
        }
        a[n-1]=n;
        a[n]=1;
    }
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<"\n";
    return ;
}
signed main(){
    lg[2]=1;
    lg[1]=0;
    for(int i=3;i<=200000;i++) lg[i]=lg[i/2]+1;
    T=read();
    while(T--) solve();
    return 0;
}