#include <bits/stdc++.h>
#define int long long
using namespace std;
int T;
string l,r;
inline int read(){
    int s=0ll,f=1ll;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1ll;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s*f;
}

void solve(){
    cin >>l>>r;
    int llen=l.size(),rlen=r.size();
    if(llen!=rlen){
        int flag=1,qwq=0;
        for(int i=1;i<rlen;i++){
            if(r[i]!='9') flag=0;
            if(r[i]!='0') qwq=1;
        }
        if(r[0]=='1'&&qwq==0){
            for(int i=1;i<rlen;i++) cout <<9;
            cout <<endl;
            return ;
        }
        if(r[0]=='1'){
            int pos;
            for(int i=1;i<rlen;i++){
                if(r[i]!='0'){
                    pos=i;
                    break;
                }
            }
            int qwq=1;
            for(int i=pos+1;i<rlen;i++){
                if(r[i]!='9') qwq=0;
            }
            for(int i=pos+1;i<rlen;i++) cout <<9;
            if(qwq) cout <<r[pos];
            else cout <<(char)(r[pos]-1);
            for(int i=pos-1;i>=0;i--){
                cout <<r[i];
            }
            cout <<endl;
            return ;
        }
        
        for(int i=1;i<rlen;i++) cout <<9;
        if(flag) cout <<r[0];
        else cout <<(char)(r[0]-1);
        
        cout <<endl;
        return ;
    }
    int now=-1;
    for(int i=0;i<llen;i++){
        if(l[i]!=r[i]){
            now=i;
            break;
        }
    }
    if(now==-1){
        int cnm=0;
        for(int i=llen-1;i>=0;i--){
            if(l[i]!='0'){
                cnm=i;
                break;
            }
        }
        for(int i=cnm;i>=0;i--) cout <<l[i];
        cout <<endl;
        return ;
    }
    int flag=1;
    for(int i=now+1;i<rlen;i++){
        if(r[i]!='9') flag=0;
    }
    for(int i=now+1;i<rlen;i++) cout <<9;
    if(flag) cout <<r[now];
    else cout <<(char)(r[now]-1);
    
    for(int i=now-1;i>=0;i--) cout <<r[i];
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}