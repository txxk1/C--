#include <bits/stdc++.h>

using namespace std;
int Q,op,x,stb[800005],sta[800005],top,t[20];
char ch;
void solve(){
    cin >>op;
    if(op==1){
        cin >>ch;
        if(ch=='(') x=1;
        else x=-1;
        top++;
        sta[top]=sta[top-1]+x;
        stb[top]=min(stb[top-1],sta[top]);
    }
    else top--;
    if(sta[top]==0&&stb[top]==0) cout <<"Yes"<<endl;
    else cout <<"No"<<endl;
    return ;
}
int main(){
    cin >>Q;
    while(Q--) solve();
    return 0;
}