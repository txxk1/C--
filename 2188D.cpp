#include <bits/stdc++.h>
#define int long long
#define inf (1ll<<30)
using namespace std;
int T,x,y;
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
    int p=0,q=0,flag=0,pos=0,m=0,n=0,now=0;
    cin >>x>>y;
    for(int i=30;i>=0;i--){
        int a=((x>>i)&1);
        int b=((y>>i)&1);
        if(a+b==2){
            flag=1;
            pos=i;
            break;
        }
    }
    if(flag==0){
        cout <<x<<" "<<y<<endl;
        return ;
    }
    for(int i=30;i>pos;i--){
        int a=((x>>i)&1);
        int b=((y>>i)&1);
        if(a) p+=(1<<i);
        if(b) q+=(1<<i);
    }
    p+=(1<<pos);
    for(int i=pos-1;i>=0;i--){
        q+=(1<<i);
    }
    cout <<p<<" "<<q<<endl;

    int dep=abs(p-x)+abs(q-y);
    for(int i=30;i>=0;i--){
        if((1<<i)>=x) m=(1<<i),now=i;
    }
    int qwq=m-x;
    n=y;
    if(((y>>now)&1)==1){
        int sx=(y%(1<<now))+1,sy=inf;
        if(((y>>now)&2)==0) sy=(1<<now)-(y%(1<<now));
        if(sx>sy) n=y+sy;
        else n=y-sx;
        qwq+=min(sx,sy);
    } 
    //1011
    if(dep>qwq){
        p=m;
        q=n;
    }
    //cout <<p<<" "<<q<<endl;

    dep=abs(p-x)+abs(q-y);
    for(int i=30;i>=0;i--){
        if((1<<i)>=y) n=(1<<i),now=i;
    }
    qwq=n-y;
    m=x;
    if(((x>>now)&1)==1){
        int sx=(x%(1<<now))+1,sy=inf;
        if(((x>>now)&2)==0) sy=(1<<now)-(x%(1<<now));
        if(sx>sy) m=x+sy;
        else m=x-sx;
        qwq+=min(sx,sy);
    } 

    if(dep>qwq){
        p=m;
        q=n;
    }
    //cout <<p<<" "<<q<<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}