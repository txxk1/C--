#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,k;
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
int get(int x){
    int ans=0,now=x;
    while(now){
        ans+=now%10;
        now=now/10;
    }
    return ans;
}
int getlen(int x){
    int now=x,ans=0;
    while(now){
        ans++;
        now=now/10;
    }
    return ans;
}
char n[105];
struct node{
    int x,id;
}t[105];
bool cmp(node p,node q){
    return p.x<q.x;
}
void solve(){
    int ans=0;
    k=0;
    cin >>n;
    for(int i=0;i<strlen(n);i++){
        t[i+1].x=n[i]-'0';
        t[i+1].id=i+1;
        ans+=t[i+1].x;
    }
    t[1].x--;
    sort(t+1,t+1+strlen(n),cmp);
    if(ans<10){
        cout <<0<<endl;
        return ;
    }
    for(int i=strlen(n);i>=1;i--){
        ans-=t[i].x;
        //if(t[i].id==1) ans++;
        if(ans<10){
            cout <<strlen(n)-i+1<<endl;
            return ;
        }
    }
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}