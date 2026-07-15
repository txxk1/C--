#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,q;
int s[505][505];
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
void print(){
    cout <<"Print"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout <<s[i][j]<<" ";
        }
        cout <<endl;
    }
}
void solve(){
    int maxn=-1,maxnx,maxny;
    n=read(),m=read(),q=read();
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            int qwq=read();
            for(int i=-2;i<=2;i++){
                for(int j=-2;j<=2;j++){
                    if(x+i<1||x+i>n) continue;
                    if(y+j<1||y+j>m) continue;
                    if(abs(i)+abs(j)<=2) s[x+i][y+j]+=qwq;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]>maxn){
                maxn=s[i][j];
                maxnx=i;
                maxny=j;
            }
        }
    }
    //print();
    while(q--){
        int x=read(),y=read(),z=read();
        for(int i=-2;i<=2;i++){
            for(int j=-2;j<=2;j++){
                if(x+i<1||x+i>n) continue;
                if(y+j<1||y+j>m) continue;
                if(abs(i)+abs(j)<=2){
                    s[x+i][y+j]+=z;
                    if(s[x+i][y+j]>maxn){
                        maxn=s[x+i][y+j];
                        maxnx=x+i;
                        maxny=y+j;

                    }
                }
            }
        }
        //print();
        cout <<maxnx<<" "<<maxny<<"\n";
    }
    return ;
}
signed main(){
    solve();
    return 0;
}