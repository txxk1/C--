#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int a[505][505];
char mp[505][505];
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
    int ans=0,flag=1;
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >>mp[i][j];
            a[i][j]=0;
        }
    }
    for(int i=0;i<=n;i++){
        a[i][m+1]='?';
        a[i][0]='?';
    }
    for(int i=0;i<=m;i++){
        a[n+1][i]='?';
        a[0][i]='?';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='.'){
                ans++;
                if(i!=1||j!=m) flag=0;
            }
            if(mp[i][j]=='U'){
                if(mp[i-1][j]!='C') flag=0;
                a[i-1][j]++;
            }
            if(mp[i][j]=='D'){
                if(mp[i+1][j]!='C') flag=0;
                a[i+1][j]++;
            }
            if(mp[i][j]=='L'){
                if(mp[i][j-1]!='C') flag=0;
                a[i][j-1]++;
            }
            if(mp[i][j]=='R'){
                if(mp[i][j+1]!='C') flag=0;
                a[i][j+1]++;
            }
            if(mp[i][j]=='C') a[i][j]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='C'){
                if(a[i][j]!=3) flag=0;
                if(mp[i][j-1]=='R'&&mp[i][j+1]=='L') flag=0;
                if(mp[i+1][j]=='U'&&mp[i-1][j]=='D') flag=0;
            }
        }
    }
    if(ans!=1) flag=0;
    if(flag==0) cout <<"No"<<endl;
    else cout <<"Yes"<<endl;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}
/*
2
4 4
CLD.
UDCL
DCLD
CLRC
2 3
DRC
CLU
*/