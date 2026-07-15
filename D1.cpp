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
int T,l,r,a[200005],t[200005];
void solve(){
    l=read(),r=read();
    int maxk=0;
    while((1<<maxk)<=r){
        maxk++;
    }
    cout <<r*r+r<<endl;
    memset(a,0,sizeof(a));/*
    for(int i=r;i>=1;i--){
        if(t[i]) continue;
        if(x+x+1-i<=r&&t[x+x+1-i]==0){
            t[x+x+1-i]=1;
            t[i]=1;
            //a[x-i]=i;            
            a[i]=x+x+1-i;
            a[x+x+1-i]=i;
        }
        else{
            a[i]=x-i;
            t[x-i]=1;
        }
    }
*/
    for(int i=r;i>=0;i--){
        if(a[i]) continue;
        for(int k=maxk;k>=0;k--){
            int j=(1<<k)-1-i;
            if(j<0||j>r) continue;
            if(a[i]==0&&a[j]==0){
                a[i]=j;
                a[j]=i;
                break;
            }
        }
    }
    for(int i=0;i<=r;i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
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