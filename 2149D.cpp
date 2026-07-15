#include <bits/stdc++.h>
#define int long long
using namespace std;
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
int T,n,s1[200005],s2[200005],a[200005],s[200005];
void solve(){
    int cnt=0,sum=0,now=0;
    n=read();
    a[0]=114514;
    a[n+1]=114514;
    for(int i=1;i<=n;i++){
        char ch=getchar();
        if(ch=='a') a[i]=1;
        else a[i]=0;
    }
    for(int i=1;i<=n;i=now){
        now=i;
        sum=1;
        while(a[now]==a[now+1]){
            now++;
            sum++;
        }
        s[++cnt]=sum;
        now++;
    }
    s1[1]=s[1];
    s2[2]=s[2];
    for(int i=3;i<=cnt;i+=2){
        s1[i]=s1[i-2]+s[i];
    }
    for(int i=4;i<=cnt;i+=2){
        s2[i]=s2[i-2]+s[i];
    }
    if(cnt<=3){
        cout <<0<<endl;
        return ;
    }
    int ans=5e10;
    int ans1=0,jn;
    for(int i=3;i<=cnt;i+=2){
        ans1+=s2[i-1]*s[i];
    }
    if(cnt%2==1) jn=cnt;
    else jn=cnt-1;
    for(int i=1;i<=cnt;i+=2){
        int qwq=ans1+s[i+1]*(2*s1[i]-s1[jn]);
        ans=min(min(ans,ans1),qwq);
        ans1=qwq;
    }
    int ans2=0,on;
    for(int i=4;i<=cnt;i+=2){
        ans2+=s[i]*(s1[i-1]-s1[1]);
    }
    if(cnt%2==0) on=cnt;
    else on=cnt-1;
    for(int i=2;i<=cnt;i+=2){
        int qwq=ans2+s[i+1]*(2*s2[i]-s2[on]);
        ans=min(min(ans,ans2),qwq);
        ans2=qwq;
    }
    cout <<ans<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
0 1 2 3 4 5 6 7 8 9 
7 8 5 4 3 2 9 0 1 6

9 8 5 4 3 2 1 0 7 6 

18+42
*/