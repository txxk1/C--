#include <bits/stdc++.h>
using namespace std;
int T,n,m,t[25],ans[200003];
struct node{
    int id,x;
}a[200003],b[200004];
void solve(){
    cin >>n;
    for(int i=1;i<=20;i++) t[i]=0;
    for(int i=1;i<=n;i++){
        cin >>a[i].x;
        a[i].id=i;
        ans[i]=-1;
        if(a[i].x!=-1) t[a[i].x]++;
    }
    a[n+1].x=0;
    int maxn=n+1,minn=0,cnt=n;
    for(int i=1;i<=n;i++){
        if(t[i]==0) break;
        int flag=i%2,bcnt=0;
        for(int j=1;j<=cnt;j++){
            if(a[j].x==i){
                //a[j].x=0;
                int now=j;
                while(a[now].x==i) a[now].x=0,now++;
                if(flag==1){
                    if(j==1){
                    for(int k=j;k<now;k++){
                        ans[a[k].id]=--maxn;
                    }
                    }
                    else{
                    for(int k=now-1;k>=j;k--){
                        ans[a[k].id]=--maxn;
                    }
                    }
                }
                else{
                    if(j==1){
                        for(int k=j;k<now;k++){
                            ans[a[k].id]=++minn;
                        }
                    }
                    else{
                        for(int k=now-1;k>=j;k--){
                            ans[a[k].id]=++minn;
                        }
                    }
                }
                j=now-1;
            }
        }
        for(int j=1;j<=cnt;j++){
            if(a[j].x!=0){
                b[++bcnt]=a[j];
            }
        }
        for(int j=1;j<=bcnt;j++){
            a[j]=b[j];
        }
        a[bcnt+1].x=0;
        cnt=bcnt;
    }
    for(int i=1;i<=n;i++){
        if(ans[i]!=-1) cout <<ans[i]<<" ";
        else cout <<minn+1<<" ";
    }
    cout <<endl;
    return ;
}
// 111
// 6 5 4  
int main(){
    cin >>T;
    while(T--) solve();
    return 0;
}

/*
1
3
-1 1 2
*/