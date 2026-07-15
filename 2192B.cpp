#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,b[200005],cnt,z[200005],zcnt;
char a[200005];
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
    zcnt=0;
    cnt=0;
    int ans=0;
    cin >>n;
    cin >>a;
    for(int i=0;i<n;i++){
        if(a[i]=='1') b[++cnt]=i+1;
        else z[++zcnt]=i+1;
    }
    if(cnt==0){
        cout <<0<<endl;
        return ;
    }
    if(cnt%2==1&&zcnt%2==0){
        cout <<-1<<endl;
        return ;
    }
    if(cnt%2==0){
        ans=cnt;
    }
    if(zcnt%2==1){
        ans=min(zcnt,ans);
    }
    if(ans==cnt){
        cout <<cnt<<endl;
        for(int i=1;i<=cnt;i++){
            cout <<b[i]<<" ";
        }
        cout <<endl;
        return ;
    }
    cout <<zcnt<<endl;
    for(int i=1;i<=zcnt;i++){
        cout <<z[i]<<" ";
    }
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}