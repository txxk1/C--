#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,y,p[200005];
int a[200005],b[200005];
char s[200005];
inline int read(){
    int s=0,f=-1;
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
int maxn(int x){
    return x/2+1;
}
/*

*/
void solve(){
    int ans=0,sum=0;
    cin >>n>>x>>y;
    cin >>s+1;
    int sx=0,sy=0,tx=0,ty=0;
    for(int i=1;i<=n;i++){
        cin >>p[i];
        sum+=p[i];
        if(s[i]=='0'){
            tx++;
            sx+=maxn(p[i]);

        }
        else{
            ty++;
            sy+=maxn(p[i]);

        }
    }
    if(sum>x+y){
        cout <<"NO"<<endl;
        return ;
    }
    if(sx>x||sy>y){
        cout <<"NO"<<endl;
        return ;
    }
    if(tx==n&&x-y<n){
        cout <<"NO"<<endl;
        return ;
    }
    if(ty==n&&y-x<n){
        cout <<"NO"<<endl;
        return ;
    }
    cout <<"YES"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}