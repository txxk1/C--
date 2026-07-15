#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int t[50005][30],s[50005][30],ans[50005];
char a[50005];
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
bool check(int x){
    for(int i=1;i<=x;i++){
        for(int j=1;j<=26;j++){
            s[i][j]=0;
        }
    }
    for(int i=1;i<=x;i++){
        for(int j=i;j<=n;j+=x){
            for(int k=1;k<=26;k++){
                s[i][k]+=t[j][k];
            }
        }
    }
    int flag=0,cnt=0;
    for(int i=1;i<=x;i++){
        int j;
        for(j=1;j<=26;j++){
            if(s[i][j]==n/x){
                ans[++cnt]=j;
                j=30;
            }
        }
        if(cnt!=i) return false;
    }
    for(int i=1;i<=n/x;i++){
        for(int j=1;j<=x;j++){
            cout <<(char)(ans[j]+'a'-1);
        }
    }
    cout <<"\n";
    return true;
}
void solve(){
    int ans=0;
    n=read(),k=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=26;j++){
            t[i][j]=0;
        }
    }
    for(int i=1;i<=k;i++){
        cin >>a;
        for(int j=0;j<n;j++){
            t[j+1][a[j]-'a'+1]=1;
        }

    }
    for(int i=1;i<=n;i++){
        if(n%i==0){
            if(check(i)==true) return ;
        }
    }
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}