#include <bits/stdc++.h>

using namespace std;
int T,n,a[100005],t[3];
int ans1,ans2;
void solve(){
    cin >>n;
    ans1=-1;
    ans2=-1;
    t[0]=0;
    t[1]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        t[a[i]%2]++;
    }
    if(t[0]>1){
        int cnt=0,b[5];
        for(int i=1;i<=n;i++){
            if(cnt>2) continue;
            if(a[i]%2==0) b[++cnt]=a[i];
        }
        ans1=b[1];
        ans2=b[2];
    }
    else if(n>32){
        for(int i=2;i<=n;i++){
            if((a[i]%a[i-1])%2==0){
                ans1=a[i-1];
                ans2=a[i];
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[j]%a[i])%2==0){
                    ans1=a[i];
                    ans2=a[j];
                }
            }
        }
    }
    if(ans1==-1) cout <<-1<<endl;
    else cout <<ans1<<" "<<ans2<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}