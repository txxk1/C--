#include <bits/stdc++.h>

using namespace std;
int T,n,l,r,ans,ansl,ansr;
void solve(){
    int now,x,flag=0;
    cin >>n;
    l=1,r=n;
    cout <<1<<" "<<1<<" "<<n<<endl;
    cin >>now;
    cout <<2<<" "<<1<<" "<<n<<endl;
    cin >>x;
    ans=x-now;
    if(ans==n){
        cout <<"! "<<1<<" "<<n<<endl;
        return ;
    }
    ansl=0;
    ansr=0;
    while(l<=r){
        int mid=(l+r)/2,qwq;
        cout <<1<<" "<<1<<" "<<mid<<endl;
        cin >>now;
        cout <<2<<" "<<1<<" "<<mid<<endl;
        cin >>x;
        qwq=x-now; 
        if(qwq==ans){
            r=mid-1;
            flag=1;
        }
        else if(qwq==0){
            l=mid+1;
            flag=-1;
        }
        else{
            ansl=mid-qwq+1;
            l=mid+1;
            break;
        } 
    }
    
        if(ansl==0){/*
            for(int i=l+1;i>=l-1;i--){
            cout <<1<<" "<<i<<" "<<i<<endl;
            cin >>now;
            cout <<2<<" "<<i<<" "<<i<<endl;
            cin >>x;
            if(x==now){
                ansl=i+1;
                break;
            }            
            }*/
           ansl=l;
        }
        cout <<1<<" "<<ansl<<" "<<n<<endl;
        cin >>now;
        cout <<2<<" "<<ansl<<" "<<n<<endl;
        cin >>x;
        ansr=ansl+x-now-1;
    
    cout <<"! "<<ansl<<" "<<ansr<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}