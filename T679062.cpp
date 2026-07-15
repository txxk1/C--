#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
string a;
void solve(){
    cin >>a;
    n=a.size();
    if(n==1){
        cout <<0<<endl;
        return ;
    }
    else if(n==2){
        if(a[0]==a[1]) cout <<1<<endl;
        else cout <<0<<endl;
        return ;
    }
    int flag=1,sum=0;
    if(a[0]==a[n-1]) flag=0;
    if(flag==1){
        int now;
        for(int i=0;i<n;i=now){
            now=i+1;
            while(a[now]==a[now-1]){
                now++;
            }
            if((now-i)%2==0&&flag==1){
                sum--;
                flag=0;
            }
            sum+=(now-i)/2;
        }
    }
    else{
        int now=0,qwq=1,tag=n-1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]) now=i;
            else break;
        }
        if(now==n-1){
            cout <<n/2<<endl;
            return ;
        }
        for(int i=n-1;i>=1;i--){
            if(a[i]==a[i-1]) tag=i-1;
            else break;
        }
        if(qwq==1&&(now+1+n-tag)%2==0){
            sum--;
            qwq=0;
        }
        //cout <<now+1+n-tag<<endl;
        sum+=(now+1+n-tag)/2;
        for(int i=now;i<tag;i=now){
            now=i+1;
            while(a[now]==a[now-1]){
                now++;
            }
            if(qwq==1&&(now-i)%2==0){
                sum--;
                qwq=0;
            }
            sum+=(now-i)/2;
        }
        
    }
    cout <<sum<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--)solve();
    return 0;
}