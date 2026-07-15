#include <bits/stdc++.h>
using namespace std;
int T,n,m;
char a[105]="0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
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
int add(int x){
    return (x+1)%4;
}
int del(int x){
    return (x+3)%4;
}
int c(int x){
    if(x==0) return 0;
    if(x==1) return 3;
    if(x==2) return 2;
    if(x==3) return 1;
    return x;
}
int cc(int x){
    if(x==0) return 2;
    if(x==1) return 1;
    if(x==2) return 0;
    if(x==3) return 3;
    return x;
}
void solve(){
    int now=0;
    for(int i=0;i<100;i++){
        if(a[i]=='0') now=3-now;
        if(a[i]=='1') now=c(now);
        if(a[i]=='2') now=now^1;
        if(a[i]=='3') now=cc(now);
        if(a[i]=='4') now=add(now);
        if(a[i]=='5') now=del(now);
        cout <<now;
    }
    return ;
}
signed main(){
    solve();
    return 0;
}