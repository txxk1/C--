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
    cin >>a;
    anscnt=0;
    for(int i=0;i<n;i++){
        sum+=(a[i]=='0');
    }
    for(int i=0;i<sum;i++){
        if(a[i]=='1') ans[++anscnt]=i+1;
    }
    for(int i=sum;i<n;i++){
        if(a[i]=='0') ans[++anscnt]=i+1;
    }
    if(anscnt==0){
        cout <<"Bob"<<endl;
    }
    else{
        cout <<"Alice"<<endl;
        cout <<anscnt<<endl;
        for(int i=1;i<=anscnt;i++){
            cout <<ans[i]<<" ";
        }
        cout <<endl;
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}