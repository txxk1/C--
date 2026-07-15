#include <bits/stdc++.h>
#define eps 1e-9
#define int long long
using namespace std;
double xa,ya,xb,yb;
inline int read(){
    int s=0ll,f=1ll;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1ll;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
void debug(){
    cout <<"BUg"<<endl;
}
void solve(){
    // y=kx+b;
    // b=y-kx;
    cin >>xa>>ya;
    cin >>xb>>yb;

    if(abs(ya-yb)<eps){
        double len=abs(xa-xb);
        double ans=len*abs(yb)*0.50;
        if(abs(ans-2.0)<eps){
            cout <<0<<endl;
        }
        else cout <<"no answer"<<endl;
        return ;
    }    
    if(abs(xa-xb)<eps){
        double len=4.0/abs(ya-yb);
        debug();
        printf("%.9lf",xa+len);
        //cout <<xa<<endl;
        return ;
    }
    double k=(ya-yb)/(xa-xb);
    double b=ya-k*xa;
    double x=-b/k;
    double len=4.0/abs(ya-yb);
    printf("%.9lf",x+len);
    return ;
}

signed main(){
    solve();
    return 0;
}