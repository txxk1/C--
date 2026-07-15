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
    cin >>n;
    cin >>a;
    int f1=0,f2=1;
    for(int i=0;i<strlen(a)-3;i++){
        if(a[i]=='2'){
            if(a[i+1]=='0'){
                if(a[i+2]=='2'){
                    if(a[i+3]=='5') f2=0;
                    if(a[i+3]=='6') f1=1;
                }
            }
        }
    }
    if(f1+f2>0) cout <<0<<endl;
    else cout <<1<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}