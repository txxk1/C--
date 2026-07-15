#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mod=1e9+7;
int T,n,k,a[123];
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

    k=read(),n=read();
    while(n%2==0){
        n=n/2;
        k--;
    }
    int ans=0,now=n,nxt=(1ll<<(k+1))-now;
    while(now!=(1ll<<k)){
        if(now<(1ll<<k)){
            now=now*2;
            nxt=(1ll<<(k+1))-now;
            a[++ans]=1;
        }
        else{
            nxt=nxt*2;
            now=(1ll<<(k+1))-nxt;
            a[++ans]=2;
        }
    }
    cout <<ans<<endl;
    for(int i=ans;i;i--){
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
/*
110111011
100000000
100000000
x 2^(K+1)-x
2x 2^(K+1)-2x
4x-2^(k+1) 2^(K+2)-4x
*/