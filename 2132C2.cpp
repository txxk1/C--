#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,s[105],now,t[105],ans,cnt;

void solve(){
    cin >>n>>k;
    ans=n*3;
    cnt=0;
    for(int i=now;i>=0;i--){
        t[i]=0;
        while(n>=s[i]){
            //ans+=s[i-1]*i;
            n-=s[i];
            cnt++;
            t[i]++;
        }
    }
    if(cnt>k) cout <<-1<<endl;
    else{
        int res=k-cnt;
        for(int i=now;i>=0;i--){
            /*
            while(t[i]>0&&res>1){
                t[i]--;
                t[i-1]+=3;
                res-=2;
            }
            */
            if(t[i]>0&&res>1){
                int minn=min(t[i],res/2);
                t[i]-=minn;
                t[i-1]+=minn*3;
                res-=minn*2;
            }
        }
        for(int i=now;i>=0;i--){
            ans+=s[i-1]*t[i]*i;
        }
        //ans+=t[0];
        cout <<ans<<endl;
    }
    return ;
}
signed main(){
    s[0]=1ll;
    for(int i=1;i<=100;i++){
        s[i]=s[i-1]*3ll;
        now=i;
        if(s[i]>1e9) break;
    }
    cin >>T;
    while(T--) solve();
    return 0;
}