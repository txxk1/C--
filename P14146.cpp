#include <bits/stdc++.h>
using namespace std;
int T,n,m,u[100005],v[100005],t[100005],cnt;
vector<int> Q;
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<1)+(s<<3)+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
void print(int x,int y){
    int a[10];
    int sum=0;
    for(int i=1;i<=6;i++){
        if(i==x) continue;
        if(i==y) continue;
        a[++sum]=i;
    }
    cout <<6<<" "<<x<<" "<<y<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
    cout <<4<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
    for(int i=1;i<=4;i++){
        cout <<3<<" "<<x<<" "<<y<<" "<<a[i]<<endl;
    }
    return ;
}
void solve(){
    n=read();
    m=read();
    for(int i=1;i<=m;i++){
        u[i]=read();
        v[i]=read();
    }
    for(int i=1;i<=m;i++){        
        if(u[i]==1){
            t[v[i]]++;
            continue;
        }
        if(v[i]==1){
            t[u[i]]++;
            continue;
        }
        t[u[i]]++;
        t[v[i]]++;
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(t[i]%2==1) Q.push_back(i);
    }
    if(Q.size()==0){
        cout <<cnt<<endl;
        for(int i=1;i<=m;i++){
            if(u[i]!=1&&v[i]!=1) cout <<3<<" "<<1<<" "<<u[i]<<" "<<v[i]<<endl;
        }
        return ;
    }
    if(Q.size()==1){
        cout <<cnt+6<<endl;
        for(int i=1;i<=m;i++){
            if(u[i]!=1&&v[i]!=1) cout <<3<<" "<<1<<" "<<u[i]<<" "<<v[i]<<endl;
        }
        print(1,Q[0]);
    }
    if(Q.size()==2){
        cout <<cnt+7<<endl;
        for(int i=1;i<=m;i++){
            if(u[i]!=1&&v[i]!=1) cout <<3<<" "<<1<<" "<<u[i]<<" "<<v[i]<<endl;
        }
        cout <<3<<" "<<1<<" "<<Q[0]<<" "<<Q[1]<<endl;
        print(Q[0],Q[1]);
    }
    if(Q.size()>=3){
        //cout <<cnt<<endl;
        cout <<cnt+2*((Q.size())/3)<<endl;
        for(int i=1;i<=m;i++){
            if(u[i]!=1&&v[i]!=1) cout <<3<<" "<<1<<" "<<u[i]<<" "<<v[i]<<endl;
        }
        int qwq=Q.size()/3*3-3,asd=Q.size()-qwq;
        for(int i=0;i<qwq;i+=3){
            cout <<3<<" "<<Q[i]<<" "<<Q[i+1]<<" "<<Q[i+2]<<endl;
            cout <<4<<" "<<1<<" "<<Q[i]<<" "<<Q[i+1]<<" "<<Q[i+2]<<endl;
        }
        
        cout <<asd<<" ";
        for(int i=qwq;i<Q.size();i++) cout <<Q[i]<<" ";
        cout <<endl;
        cout <<asd+1<<" "<<1<<" ";
        for(int i=qwq;i<Q.size();i++) cout <<Q[i]<<" ";
        cout <<endl;
    }
    return ;
}

signed main(){
    solve();
    return 0;
}