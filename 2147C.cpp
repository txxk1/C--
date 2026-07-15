#include <bits/stdc++.h>
#define int long long

using namespace std;
const int mod=1e9+7;
int T,n,a[200005];
inline int read(){
    int s=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}
void solve(){
    n=read();
    for(int i=1;i<=n;i++){
        char ch=getchar();
        a[i]=ch-'0';
    }
    if(n<=2){
        cout <<"YES"<<endl;
        return ;
    }
    a[0]=a[n+1]=1;
    int single=0,ans=0;
    if(a[1]==0) ans++;
    for(int i=2;i<=n-1;i++){
        if(a[i]==0){
            if(a[i-1]==1&&a[i+1]==1){
                if(a[i-2]==1&&a[i+2]==1){
                    cout <<"NO"<<endl;
                    return ;
                }
                else single++;
            }
            else ans++;
        }
        else {
            if(a[i+1]==1){
                if(single%2==1&&ans==0){
                    cout <<"NO"<<endl;
                    return ;
                }
                single=0;
                ans=0;
            }
        }
    }

    if(a[n]==0) ans++;
    if(single%2==1&&ans==0) cout <<"NO"<<endl;
    else cout <<"YES"<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
101010110
*/