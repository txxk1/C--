#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,m,C[64][64];
int a[66],nxt[66],s[66];
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
    cin >>n>>k;
    int d;
    for(int i=1;i<=64;i++) a[i]=0;
    for(int i=0;i<=30;i++){
        if((1<<i)==n) d=i;
    }
    if(n==1){
        if(k>=1) cout <<0<<endl;
        return ;
    }
    if(n==2){
        if(k==1) cout <<1<<endl;
        if(k>=2) cout <<0<<endl;
        return ;
    }
    if(k>2*d-2){
        cout <<0<<endl;
        return ;
    }
    a[1]=1;
    a[2]=1;
    for(int i=2;i<=d;i++){
        for(int j=i+1;j<=2*i-1;j++){
            a[j]+=C[i-1][j-i];
        }
        // i=3 j4->5 C21+C22
        a[i+1]++;
    }
    int sum=0;
    for(int i=k+1;i<=2*d-1;i++){
        sum+=a[i];
    }
    cout <<sum<<endl;
    return ;
}
signed main(){
    C[0][0]=1;
    for(int i=1;i<=30;i++){
        C[i][0]=1;
        C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    T=read();
    while(T--) solve();
    return 0;
}