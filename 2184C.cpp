#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,m;
int a[100005];
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
int dfs(int x,int dep){
    if(x==n) return dep;
    if(x>n) return -1;
    return max(dfs(x*2,dep+1),max(dfs(x*2+1,dep+1),dfs(x*2-1,dep+1)));
}
void solve(){
    int ans=0;
    cin >>n>>k;
    if(n==k){
        cout <<0<<endl;
        return ;
    }
    for(int i=1;i<=30;i++){
        //if(k>(n<<i)) break;
        if(abs((k<<i)-n)<(1<<(i))){
            cout <<i<<endl;
            return ;
        }
    }
    cout <<-1<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
/*
63
62
31
30
15
14
7
6
3
2
1
2^(k)-1 2k-2
15 16
7 8 8 8
*/