#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mod=1e9+7;
int T,n,m,a[205];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}
void solve(){
    int sum=0,flag=0;
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        a[i]=read();
        sum=max(sum,a[i]);
        if(a[i]<=a[i-1]){
            flag=1;
        }
    }
    if(flag) cout <<1<<endl;
    else cout <<n-sum+1<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
