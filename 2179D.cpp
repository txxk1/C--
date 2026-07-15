#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=(1<<16)+2;
int T,n,k;
int a[maxn];
inline int read(){
    int s=0,f=-1;
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
    cin >>n;
    a[1]=(1<<n)-1;
    int cnt=1,now=(1<<n)-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<i);j++){
            a[++cnt]=j*(1<<(n-i))+(1<<(n-i-1))-1;
        }
    }
    for(int i=1;i<=(1<<n);i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// 1111
// 0111
// 0011
// 1011
// 111
// 011
// 001
// 011
// 000