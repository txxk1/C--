#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,q[30],p[30],res[30];
char s[100005],t[100005];
void solve(){
    int flag=0;
    cin >>s;
    cin >>t;
    for(int i=1;i<=26;i++) q[i]=0,p[i]=0;
    for(int i=0;i<strlen(s);i++){
        if(flag==0){
            if(s[i+1]-'a'>s[i]-'a') flag=1;
            if(s[i+1]-'a'<s[i]-'a') flag=-1;
        }
        q[s[i]-'a'+1]++;
    }
    for(int i=0;i<strlen(t);i++) p[t[i]-'a'+1]++;
    for(int i=1;i<=26;i++){
        if(q[i]>p[i]){
            cout <<"Impossible"<<endl;
            return ;
        }
        res[i]=p[i]-q[i];
    }
    for(int i=0;i<strlen(s);i++){
        for(int j=1;j<s[i]-'a'+1;j++){
            for(int k=1;k<=res[j];k++){
                cout <<(char)(j+'a'-1);
                //res[j]--;
            }
            res[j]=0;
        }
        cout <<s[i];
    }
    for(int i=1;i<=26;i++){
        for(int j=1;j<=res[i];j++){
            cout <<(char)(i+'a'-1);
        }
    }
    cout <<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// 