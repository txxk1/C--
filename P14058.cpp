#include <bits/stdc++.h>

using namespace std;
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
int T,n,m,a[60000005];
char ch;
void solve(){
    int ans=1;
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        a[i+n]=a[i];
    }
    int fmin=a[1],fmax=a[1],now=-1;
    for(int i=2;i<=2*n;i++){        
        fmin=min(fmin,a[i]);
        fmax=max(fmax,a[i]);
        if(fmax-fmin>m){
            ans++;
            fmin=a[i];
            fmax=a[i];
        }
    }
    ans=ans/2;
    if(ans==0) cout <<1<<endl;
    else cout <<ans<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}