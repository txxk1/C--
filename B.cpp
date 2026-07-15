#include <bits/stdc++.h>
using namespace std;
vector<int> t[100005];
int T,n,m,a[100005],s,x;
int read(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
    return k*f;
}
void solve(){
    memset(a,0,sizeof(a));
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        //while(!t[i].empty()) t[i].pop_back();
        t[i].clear();
    }
    //cin >>n>>m;
    for(int i=1;i<=n;i++){
        s=read();
        //cin >>s;
        for(int j=1;j<=s;j++){
            x=read();
            t[i].push_back(x);
            //cin >>x;
            a[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        if(a[i]==0){
            cout <<"NO"<<endl;
            return ;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int ad=1;
        for(int j=0;j<t[i].size();j++){
            if(a[t[i][j]]==1) ad=0;
        }
        ans+=ad;
    }/**/
    if(ans>=2) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return ;
}

int main(){
    T=read();
    //cin >>T;
    while(T--){
        solve(); 
    }
    return 0;
}
/*
1 2 6 7 8 9 
\

1
5 10
4 1 2 3 4
5 1 2 5 6 7
5 2 6 7 8 9
4 6 7 8 9
2 9 10


5 10
4 1 2 3 4
5 1 2 5 6 7
5 2 6 7 8 9
4 6 7 8 9
2 9 10
*/