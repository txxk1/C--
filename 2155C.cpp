#include <bits/stdc++.h>

using namespace std;
int T,n,a[100005],b1[100005],b2[100005];

void solve(){
    cin >>n;
    int t1=1,t2=1;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    //  1 L   2 R
    b1[1]=1;
    b2[1]=2;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            b1[i]=3-b1[i-1];
            b2[i]=3-b2[i-1];
        }
        else if(abs(a[i]-a[i-1])>1){
            cout <<0<<endl;
            return ;
        }
        else if(a[i]==a[i-1]+1){
            if(b1[i-1]==2) t1=0;
            b1[i]=1;
            if(b2[i-1]==2) t2=0;
            b2[i]=1;
        }
        else if(a[i-1]==a[i]+1){
            if(b1[i-1]==1) t1=0;
            b1[i]=2;
            if(b2[i-1]==1) t2=0;
            b2[i]=2;
        }
    }
    int vis1=1,vis2=1;
    for(int i=2;i<=n;i++){
        if(b1[i]==2) vis1++;
        if(b2[i]==2) vis2++;
    }
    if(vis1!=a[1]) t1=0;
    if(vis2!=a[1]) t2=0;
    for(int i=2;i<=n;i++){
        if(b1[i]==1&&b1[i-1]==1) vis1++;
        if(b1[i]==2&&b1[i-1]==2) vis1--;

        if(b2[i]==1&&b2[i-1]==1) vis2++;
        if(b2[i]==2&&b2[i-1]==2) vis2--;
        if(vis1!=a[i]) t1=0;
        if(vis2!=a[i]) t2=0;
    }
    cout <<t1+t2<<endl;
    return ;
    /*
    for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) t=1;
    if(t==0) {
        cout <<2<<endl;
        return ;
    }
    int c=0;
    // -1 L  -2 R
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]+1){
            if(b[i-1]==114514||b[i-1]==-1) b[i-1]=-1;
            else if(b[i-1]==-2) c=1;

            b[i]=-1;
        }
        else if(a[i]==a[i-1]-1){
            if(b[i-1]==114514||b[i-1]==-2) b[i-1]=-2;
            else if(b[i-1]==-1) c=1;
            b[i]=-2;
        }
        else{
            if(b[i-1]==-1) b[i]=-2;
            else if(b[i-1]==-2) b[i]=-1;
        }
    }
    if(c){
        cout <<0<<endl;
        return ;
    }
    cout <<1<<endl;*/
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}