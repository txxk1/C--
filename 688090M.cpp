#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y;
int a[100005];
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
    int ans=0;
    x=read(),y=read();
    if(x*1000>y||x*2500<y){
        cout <<-1<<endl;
    }
    for(int i=0;i<=x;i++){
        int res=y-i*1000;
        if(res%2500==0){
            cout <<x-i-res/2500<<" "<<i<<" "<<res/2500<<endl;
            return ;
        }
    }
    cout <<-1<<endl;
}
signed main(){
    solve();
    return 0;
}