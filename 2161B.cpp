#include <bits/stdc++.h>

using namespace std;
int T,n,pos[205],neg[305],cnt1,cnt2;
char a[105][105];
void solve(){
    cin >>n;
    cnt1=0;
    cnt2=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pos[i+j]=0;
            pos[i+j+1]=0;
            pos[i+j-1]=0;
            neg[j-i+100]=0;
            neg[j-i+99]=0;
            neg[j-i+101]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>a[i][j];
            if(a[i][j]=='#'){
                sum++;
                pos[i+j]++;
                neg[j-i+100]++;
                if(pos[i+j]==1) cnt1++;
                if(neg[j-i+100]==1) cnt2++;
            }
        }
    }        
    int qwq,qwqq;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]=='#'){
                qwq=i+j;
                qwqq=j-i+100;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=n-1;j++){
            if(a[i][j]=='#'){
                if(a[i][j+1]=='#'&&a[i][j-1]=='#'){
                    cout <<"NO"<<endl;
                    return ;
                }
            }
        }
    }    
    for(int i=1;i<=n;i++){
        for(int j=2;j<=n-1;j++){
            if(a[j][i]=='#'){
                if(a[j+1][i]=='#'&&a[j-1][i]=='#'){
                    cout <<"NO"<<endl;
                    return ;
                }
            }
        }
    }
    if(cnt1<=2){
        if(cnt1==0||cnt1==1){
            cout <<"YES"<<endl;
            return ;
        }
        if(cnt1==2){
            if(pos[qwq]>0&&pos[qwq+1]>0){
                cout <<"YES"<<endl;
                return ;
            }
            if(pos[qwq]>0&&pos[qwq-1]>0){
                cout <<"YES"<<endl;
                return ;
            }
        }
    }
    if(cnt2<=2){
        if(cnt2==0||cnt2==1){
            cout <<"YES"<<endl;
            return ;
        }
        if(cnt2==2){
            if(neg[qwqq]>0&&neg[qwqq+1]>0){
                cout <<"YES"<<endl;
                return ;
            }
            if(neg[qwqq]>0&&neg[qwqq-1]>0){
                cout <<"YES"<<endl;
                return ;
            }
        }
    }   
    if(sum==4){
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(a[i][j]=='#'){
                    if(a[i][j+1]=='#'&&a[i+1][j]=='#'&&a[i+1][j+1]=='#'){
                        cout <<"YES"<<endl;
                        return ;
                    }
                }
            }
        }
    }
    cout <<"NO"<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}


/*
#include <bits/stdc++.h>

using namespace std;
int T,n,pos[205],neg[305],cnt1,cnt2;
char a[105][105];
void solve(){
    freopen("qwq.in","r",stdin);
    freopen("std.out","r",stdout);
    cin >>n;
    cnt1=0;
    cnt2=0;
    int sum=0;
    int minpos=1e5,maxpos=-1,minneg=1e5,maxneg=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >>a[i][j];
            if(a[i][j]=='#'){
                sum++;
                minpos=min(minpos,i+j);
                maxpos=max(maxpos,i+j);
                minneg=min(minneg,i-j+100);
                maxneg=max(maxneg,i-j+100);
            }
        }
    }
    if(maxneg-minneg<=1){
        cout <<"YES"<<endl;
        return ;
    }
    if(maxpos-minpos<=1){
        cout <<"YES"<<endl;
        return ;
    }
    if(sum==4){
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(a[i][j]=='#'){
                    if(a[i][j+1]=='#'&&a[i+1][j]=='#'&&a[i+1][j+1]=='#'){
                        cout <<"YES"<<endl;
                        return ;
                    }
                }
            }
        }
    }
    cout <<"NO"<<endl;
    return ;
}
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}*/