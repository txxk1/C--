#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mod=1e9+7;
int T,n,b[200005];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}
void solve(){
    int ans=0,now=0,sum=0;
    map<int,int> a;
    n=read();
    for(int i=1;i<=n;i++){
        int x=read();
        ans+=x;
        if(x%2==1){
            if(a[x]==0) a[x]=++now;
            b[a[x]]++;
        }
    }
    sort(b+1,b+now+1);
    for(int i=now;i>=1;i--){
        if((i-now)%2==0) sum+=b[i];
        else sum-=b[i];
    }
    for(int i=1;i<=now;i++) b[i]=0;
    cout <<(ans+sum)/2<<" "<<(ans-sum)/2<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}