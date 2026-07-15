#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k;
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
struct node{
    int id,x;
}a[200005];
bool cmp(node p,node q){
    if(p.x==q.x) return p.id>q.id;
    return p.x<q.x;
}
void solve(){
    int ans=0,now=0,res=0;
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i].x;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        int qwq=(a[i].id-res)/a[i].x;
        if(qwq>=0){
            ans+=qwq;
            res+=qwq*a[i].x;
        }

    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}