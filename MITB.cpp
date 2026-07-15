#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
int a[300005],z[300005],zcnt,ans[500005],anscnt,t[300005],tcnt;
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
    int sum=0;
    n=read();
    zcnt=0;
    anscnt=0;
    tcnt=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum+=a[i];
        if(a[i]==0) continue;
        if(a[i]==1){
            z[++zcnt]=i;
        }
        else{
            t[++tcnt]=i;
        }
    }
    for(int i=1;i<=sum;i++){
        if(i%2==0){
            if(tcnt==0){
                cout <<"NO"<<endl;
                return ;
            }
            ans[i]=t[tcnt];
            a[ans[i]]--;
            if(a[ans[i]]==1){
                z[++zcnt]=ans[i];
                tcnt--;
            }
        }
        else{
            if(zcnt==0){
                ans[i]=t[tcnt];
                a[ans[i]]--;
                if(a[ans[i]]==1){
                    z[++zcnt]=ans[i];
                    tcnt--;
                }
            }
            else{
                ans[i]=z[zcnt--];
            }
        }
    }
    cout <<"YES"<<endl;
    for(int i=1;i<=sum;i++){
        cout <<ans[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}