#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
char a[200005];
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
int get(int x){
    if(x==1) return 0;
    if(x==2) return 1;
    if(x==3) return 1;
    return x/2;
}
// 3->2
// 4->3
// 5->3
// suuuus
// sususs
// suuuuus
// sususus
void solve(){
    int ans=0;
    cin >>a;
    if(a[0]=='u') ans++;
    a[0]='s';
    if(a[strlen(a)-1]=='u') ans++;
    a[strlen(a)-1]='s';
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='u'){
            int len=1;
            int now=i+1;
            while(now<strlen(a)&&a[now]=='u') now++,len++;
            i=now-1;
            ans+=get(len);
            
        }
    }
    // suuuuuu
    // sususus
    // suuuuus
    // sususus
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}