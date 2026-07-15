#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[200005],b[200005],t[200005],s[200005];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
void clear(){
    for(int i=1;i<=n;i++){
        int x=a[i],y=a[i]+1;
        for(int j=2;j*j<=a[i]+1;j++){
            while(x%j==0) s[j]=0,x=x/j;
            while(y%j==0) t[j]=0,y=y/j;
        }
        if(x!=1) s[x]=0;
        if(y!=1) t[y]=0;
    }
}
void solve(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    for(int i=1;i<=n;i++){
        int x=a[i],y=a[i]+1;
        for(int j=2;j*j<=a[i]+1;j++){
            if(x%j==0){
                s[j]++;
                x=x/j;            
                if(s[j]>=2){
                    cout <<0<<endl;
                    clear();
                    return ;
                }
            }
            while(x%j==0) x=x/j;

            if(y%j==0){
                t[j]++;
                y=y/j;
            }
            while(y%j==0) y=y/j;
        }
        if(x!=1){
            s[x]++;
            if(s[x]>=2){
                cout <<0<<endl;
                clear();
                return ;
            }
        }
        if(y!=1){
            t[y]++;
        }
    }
    for(int i=1;i<=n;i++){
        int x=a[i];
        for(int j=2;j*j<=a[i]+1;j++){
            while(x%j==0){
                if(t[j]!=0){
                    cout <<1<<endl;
                    clear();
                    return ;
                }
                x=x/j;
            }
        }
        if(x!=1){
            if(t[x]!=0){
                cout <<1<<endl;
                clear();
                return ;
            }
        }
    }
    cout <<2<<endl;
    clear();
    return ;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}