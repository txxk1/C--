#include <bits/stdc++.h>

using namespace std;
int T,n,kx,ky,dx,dy;
void solve(){
    cin >>n>>kx>>ky>>dx>>dy;
    int now=0;
    if(kx<dx) now=max(dx,now);
    if(kx>dx) now=max(n-dx,now);
    if(ky<dy) now=max(dy,now);
    if(ky>dy) now=max(n-dy,now);
    cout <<now<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}