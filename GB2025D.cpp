#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,anscnt,s[200005];
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
struct qwq{
    int x,y;
}ans[200005];
bool cmp(node q,node p){
    return q.x<p.x;
}
void print(){
    cout <<anscnt<<endl;
    for(int i=1;i<=anscnt;i++){
        cout <<ans[i].x<<" "<<ans[i].y<<endl;
    }
    return ;
}
void solve(){
    cin >>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i].x;
        a[i].id=i;
    }
    if(m>n/2){
        cout <<-1<<endl;
        return ;
    }
    anscnt=0;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i].x;
    if(m!=0){
        for(int i=1;i<=m*2;i+=2){
            ans[++anscnt].x=a[i+1].id;
            ans[anscnt].y=a[i].id;
        }
        for(int i=2*m+1;i<=n;i++){
            ans[++anscnt].x=a[i].id;
            ans[anscnt].y=a[i-1].id;
        }
        print();
    }
    else{
        if(a[n].x>s[n-1]){
            cout <<-1<<endl;
            return ;
        }
        int now=0,iid=-2;
        for(int i=n-1;i>=1;i--){
            now+=a[i].x;
            if(now>=a[n].x){
                iid=i;
                break;
            }
        }     
        for(int i=1;i<iid;i++){
            ans[++anscnt].x=a[i].id;
            ans[anscnt].y=a[i+1].id;
        }
        for(int i=iid;i<n;i++){
            ans[++anscnt].x=a[i].id;
            ans[anscnt].y=a[n].id;
        }
        print();
    }
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// 