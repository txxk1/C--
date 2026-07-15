#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
char a[100005];
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
    cin >>a;
    int d=0,t=0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='T') t++;
        if(a[i]=='D') d++;
    }
    if(t==3) cout <<"T1"<<endl;
    else cout <<"DRX"<<endl;
}
signed main(){
    solve();
    return 0;
}