#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,p[40004],prime[40004],cnt;
int a[200005];
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
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
void solve(){
    int ans=0;
    n=read();
    for(int i=1;i<=n;i++) cin >>a[i];
    if(n<=8){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(gcd(a[i],a[j])>1){
                    cout <<a[i]<<" "<<a[j]<<endl;
                    return ;
                }
            }
        }
        cout <<-1<<endl;
    }
    else{
        int lst,now,cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]%2==0){
                cnt++;
                if(cnt==1) lst=a[i];
                if(cnt==2) now=a[i];
            }
        }
        if(cnt>=2) cout <<lst<<" "<<now<<endl;
        else cout <<-1<<endl;
    }
    return ;
}
signed main(){
    for(int i=2;i<=4e4;i++){
        if(!p[i]) prime[++cnt]=i;
        for(int j=2;j*i<=4e4;j++){
            p[j*i]=1;
        }
    }
    T=read();
    while(T--) solve();
    return 0;
}