#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int a[5][5],s[5],p[5],t[10];
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
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin >>a[i][j];
            t[a[i][j]]=1;
        }
    }
    for(int i=1;i<=9;i++){
        if(t[i]==0){
            cout <<"No"<<endl;
            return ;
        }
    }
    int ans=a[1][1]+a[2][2]+a[3][3];
    if(ans!=a[1][3]+a[2][2]+a[3][1]){
        cout <<"No"<<endl;
        return ;
    }
    for(int i=1;i<=3;i++){
        int sum=0,qwq=0;
        for(int j=1;j<=3;j++){
            sum+=a[i][j];
            qwq+=a[j][i];
        }
        if(sum!=ans||qwq!=ans){
            cout <<"No"<<endl;
            return ;
        }
    }
    cout <<"Yes"<<endl;
    return ;
}
signed main(){
    solve();
    return 0;
}