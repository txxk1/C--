#include <bits/stdc++.h>

using namespace std;
int n,m,k,a[803],to[803],nxt[803],f[803];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > s;
void solve(){ 
    sort(a+1,a+1+m);
    for(int i=1;i<=m;i++){
        to[i]=1;
        nxt[i]=f[i];
        
    }
    while(!s.empty()) s.pop();
    for(int i=1;i<=m;i++){
        s.push(pair<int,int>(a[1]+nxt[i],i));
    }
    for(int i=1;i<=m;i++){
        f[i]=s.top().first;
        int qwq=s.top().second;
        s.pop();
        s.push(pair<int,int>(a[++to[qwq]]+nxt[qwq],qwq));
    }

}
int main(){
    cin >>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin >>f[i];
        //s.push(pair<int,int>(a[i],i));
    }
    sort(f+1,f+m+1);
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >>a[j];
        }
        solve();
    }
    while(k--){
        cout <<s.top().first<<" ";
        s.pop();
    }
    return 0;
}