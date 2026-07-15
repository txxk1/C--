#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x;
int a[100005],b[100005],c[100005];
inline int read(){
    int s=0ll,f=1ll;
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
    int flag=0ll,qwq=0ll,res=0ll;
    cin >>n>>x;
    for(int i=1;i<=n;i++){
        cin >>a[i]>>b[i]>>c[i];
        int TT=b[i]*a[i]-c[i];
        qwq=max(qwq,TT);
        res+=max(0ll,(TT+c[i]-a[i]));
        if(TT>0) flag=1;
    }    
    if(x<=res){
        cout <<0<<endl;
        return ;
    }
    if(!flag){
        cout <<-1<<endl;
        return ;
    }
    int ans2=(x-res)/qwq+((x-res)%qwq==0ll?0ll:1ll);
    cout <<ans2<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}