#include <bits/stdc++.h>

using namespace std;
int T,n,k,a[200005],ans[200005];
void solve(){
    cin >>n>>k;
    int head=0,tail=0,unk=0;
    for(int i=1;i<=k;i++){
        char ch=getchar();
        while(ch<'0'||ch>'9') ch=getchar();
        a[i]=ch-'0';
        ans[i]=-1;
        if(a[i]==0) head++;
        if(a[i]==1) tail++;
        if(a[i]==2) unk++;
    }
    if(n==k){
        for(int i=1;i<=n;i++) cout <<'-';
        cout <<endl;
        return ;
    }
    for(int i=1;i<=n;i++) ans[i]=-1;
    for(int i=1;i<=head;i++) ans[i]=0;
    for(int i=n;i>=n-tail+1;i--) ans[i]=0;
    for(int i=head+1;i<=min(head+unk,n-tail);i++) ans[i]=2;
    for(int i=n-tail;i>=max(head+1,n-tail-unk+1);i--) ans[i]=2;
    for(int i=1;i<=n;i++){
        if(ans[i]==0) cout <<'-';
        if(ans[i]==-1) cout <<'+';
        if(ans[i]==2) cout <<'?';
    }
    cout <<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}