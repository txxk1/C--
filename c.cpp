#include <bits/stdc++.h>
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
int T,n,a[200005],lst,pd;
char s;
void merge(int x,int y){
    if(x>=y) return ;
    for(int i=x;i<y;i++) a[i]=i+1;
    a[y]=x;
}
void solve(){
    n=read();
    lst=0;
    pd=0;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        s=getchar();
        if(s=='1'){
            a[i]=i;
            if((i-lst)==2) pd=1;
            merge(lst+1,i-1);
            lst=i;
        }
    }
    if(a[n]!=n){
        if(n-lst==1) pd=1;
        merge(lst+1,n);
    }
    if(pd==1){
        cout <<"NO"<<endl;
        return ;
    }
    cout <<"YES"<<endl;
    for(int i=1;i<=n;i++) cout <<a[i]<<" ";
    cout <<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
1 2 3 4 5 

2 3 4 5 1 
*/