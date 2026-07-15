#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,s[200005];
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
char a[200005];
int ans[200005],anscnt;
void solve(){
    int sum=0;
    cin >>n;
    cin >>a+1;
    for(int i=1;i<=n;i++) s[i]=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+(a[i]=='(');
    }
    int now=0,ans;
    for(int i=1;i<=n;i++){
        if(a[i]=='(') now++;
        if(n-i-(s[n]-s[i])>=now) ans=now;
        else break;
    }
    // i+1 n
    int flag=1;
    for(int i=1;i<=ans;i++){
        if(a[i]==')') flag=0;
    }
    if(flag==1) cout <<-1<<endl;
    else cout <<ans*2<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
1
8
(())(())
*/