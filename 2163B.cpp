#include <bits/stdc++.h>

using namespace std;
int T,n,m,p[200005];
int a[200005],now[200005];
void solve(){
    int flag=0,a1,an;
	cin >>n;
    for(int i=1;i<=n;i++){
        cin >>p[i];
        if(p[i]==1) a1=i;
        if(p[i]==n) an=i;
    }
    for(int i=1;i<=n;i++){
        char ch;
        cin >>ch;
        a[i]=ch-'0';
        if(p[i]==1&&a[i]==1) flag=1;
        if(p[i]==n&&a[i]==1) flag=1;
    }
    if(a[1]==1||a[n]==1){
        cout <<-1<<endl;
        return ;
    }
    if(flag){
        cout <<-1<<endl;
        return ;
    }
    cout <<5<<endl;
    cout <<min(1,a1)<<" "<<max(1,a1)<<endl;
    cout <<min(1,an)<<" "<<max(1,an)<<endl;
    cout <<min(a1,an)<<" "<<max(a1,an)<<endl;
    cout <<min(n,a1)<<" "<<max(n,a1)<<endl;
    cout <<min(n,an)<<" "<<max(n,an)<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// x maxn+minn
// a[1] - 1 1-n n-a[n]
// a[1] - n 
// 3 1 2 4 6 5 7 9 8 10
// 5 4 7 3 2 1 6 10 9 8
// 0 1 0 1 1 0 1 0 1 0