#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans[500005];
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
    if(n%2==1){
        flag=1;
        ans[n]=n;
        n--;
    }

    int k=n/2,cnt=0;
    for(int i=n;i>=1;i-=2){
        ans[i]=k-cnt;
        cnt++;
    }
    k=n;
    cnt=0;
    for(int i=n-1;i>=1;i-=2){
        ans[i]=k-cnt;
        cnt++;
    }
    cout <<"YES"<<endl;
    for(int i=1;i<=n+flag;i++) cout <<ans[i]<<" ";
    cout <<endl;
    return ;
}
/*
*/
signed main(){
    cin >>T;
    while(T--) solve();
}