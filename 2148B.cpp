#include <bits/stdc++.h>

using namespace std;
int T,n,m,x,y,t;
int main(){
    cin >>T;
    while(T--){
        cin >>n>>m>>x>>y;
        for(int i=1;i<=n;i++) cin >>t;
        for(int i=1;i<=m;i++) cin >>t;
        cout <<n+m<<endl;
    }
    return 0;
}