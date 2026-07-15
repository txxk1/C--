#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,p[500005],q[500005],pcnt,qcnt;
char a[1000005];
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
    int cnt=0;
    cin >>n;
    cin >>a;
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            cnt++;
            int now=i+1;
            while(a[now]=='1') now++;
            i=now-1;
        }
    }
    cout <<cnt*2-(a[n-1]=='1')<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}