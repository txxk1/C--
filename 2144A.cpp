#include <bits/stdc++.h>

using namespace std;
int T,n,a[45],s[45],t[4];
void solve(){
    cin >>n;
    t[0]=t[1]=t[2]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        a[i]=a[i]%3;
        t[a[i]]++;
        s[i]=s[i-1]+a[i];
    }
    if(s[n]%3!=0){
        cout <<0<<" "<<0<<endl;
        return ;
    }
    else{
        if(t[0]>=3){
            int now1=0,now2=0;
            for(int i=1;i<=n;i++){
                if(s[i]%3==0&&now1==0) now1=i;
                if(s[i]%3==0&&now1!=0) now2=i;
            }
            cout <<now1<<" "<<now2;
        }
        else{
            
        }
    }
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
/*
1
3 1
6 9 5
1 3
*/