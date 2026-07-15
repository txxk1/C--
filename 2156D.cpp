#include <bits/stdc++.h>

using namespace std;
int T,n,cnta,a[20005],b[20005],cntb,c[20005],cntc;
int base[200005],base0[200005],base1[200005];
int basecnt;
void solve(){
    cin >>n;
    int now=1,ans=0;
    cnta=n-1;
    cntb=0;
    cntc=0;
    basecnt=n;
    for(int i=1;i<=n-1;i++) a[i]=i;
    for(int i=1;i<=n;i++) base[i]=i;
    while(now<=n){        
        cntb=0;
        cntc=0;
        for(int i=1;i<=cnta;i++){
            int qwq;
            cout <<"? "<<a[i]<<" "<<now<<endl;
            cin >>qwq;
            if(qwq==1) b[++cntb]=a[i];
            else c[++cntc]=a[i];
        }
        int fir=0,sec=0;
        for(int i=1;i<=basecnt;i++){
            if(base[i]&now) base1[++fir]=base[i];
            else base0[++sec]=base[i];
        }
        if(cntc==sec){
            for(int i=1;i<=cntb;i++) a[i]=b[i];
            for(int i=1;i<=fir;i++) base[i]=base1[i];
            basecnt=fir;
            cnta=cntb;
            ans+=now;
        }
        else{
            for(int i=1;i<=cntc;i++) a[i]=c[i];
            for(int i=1;i<=sec;i++) base[i]=base0[i];
            basecnt=sec;
            cnta=cntc;
        }
        now=now*2;
    }
    cout <<"! "<<ans<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}