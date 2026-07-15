#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
char a[100005],b[1005];
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
    int ans=0,sum=0;
    cin >>n;
    cin >>a;
    for(int i=0;i<n;i++){
        b[i]=a[i];
        if(i!=0&&i!=n-1){
            if(a[i-1]=='1'&&a[i+1]=='1') b[i]='1';
        }
    }
    int now=0;
    while(now<n){
        int qwq=now+1;
        while(b[qwq]=='1') qwq++;
        if(qwq!=now+1)sum+=(qwq-now+1)/2;
        now=qwq;
    }
    cout <<sum<<" ";
    for(int i=0;i<n;i++){
        for(int j=1;j<n-1;j++){
            if(a[j-1]=='1'&&a[j+1]=='1') a[j]='1';
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]=='1') ans++;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}