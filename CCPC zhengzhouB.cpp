#include <bits/stdc++.h>
#define inf 2e9
using namespace std;
int n,a[105][205],ax,ay,s[105][205],dis[105][205],inq[105][205];
void BFS(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*i-1;j++){
            dis[i][j]=inf;
        }
    }
    queue<pair<int,int> > Q;
    if(s[ax][ay]==a[ax][ay]) Q.push(make_pair(ax,ay));
    inq[ax][ay]=1;
    dis[ax][ay]=0;
    while(!Q.empty()){
        int nowx=Q.front().first;
        int nowy=Q.front().second;         
        Q.pop();   
        if(nowy-1>=1&&s[nowx][nowy-1]==a[nowx][nowy-1]){
            if(!inq[nowx][nowy-1]){
                dis[nowx][nowy-1]=min(dis[nowx][nowy-1],dis[nowx][nowy]+1);
                inq[nowx][nowy-1]=1;
                Q.push(make_pair(nowx,nowy-1));
            }
        }
        if(nowy+1<=2*nowx-1&&s[nowx][nowy+1]==a[nowx][nowy+1]){
            if(!inq[nowx][nowy+1]){
                dis[nowx][nowy+1]=min(dis[nowx][nowy+1],dis[nowx][nowy]+1);
                inq[nowx][nowy+1]=1;
                Q.push(make_pair(nowx,nowy+1));
            }
        }
        if(nowy%2==0&&nowy-1<=2*nowx-3){
            if(nowx-1>=1&&s[nowx-1][nowy-1]==a[nowx-1][nowy-1]){
                if(!inq[nowx-1][nowy-1]) {
                    Q.push(make_pair(nowx-1,nowy-1));
                    inq[nowx-1][nowy-1]=1;
                    dis[nowx-1][nowy-1]=min(dis[nowx-1][nowy-1],dis[nowx][nowy]+1);
                }
                
            }
        }
        if(nowy%2==1){
            if(nowx+1<=n&&s[nowx+1][nowy+1]==a[nowx+1][nowy+1]){
                if(!inq[nowx+1][nowy+1]){
                    Q.push(make_pair(nowx+1,nowy+1));
                    inq[nowx+1][nowy+1]=1;
                    dis[nowx+1][nowy+1]=min(dis[nowx+1][nowy+1],dis[nowx][nowy]+1);
                }
            }
        }
    }
    if(dis[1][1]==inf) cout <<-1<<endl;
    else cout <<dis[1][1]<<endl;
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=2*i-1;j++){
            cout <<dis[i][j]<<" ";
        }
        cout <<endl;
    }*/
    return ;
}
int main(){
    cin >>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*i-1;j++){
            cin >>a[i][j];
        }
    }
    cin >>ax>>ay;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            s[i][1]=4;
            for(int j=2;j<=2*i-1;j++){
                if(s[i][j-1]==4) s[i][j]=3;
                if(s[i][j-1]==3) s[i][j]=2;
                if(s[i][j-1]==2) s[i][j]=1;
                if(s[i][j-1]==1) s[i][j]=4;
            }
        }
        else{
            s[i][1]=1;
            for(int j=2;j<=2*i-1;j++){
                if(s[i][j-1]==4) s[i][j]=1;
                if(s[i][j-1]==3) s[i][j]=4;
                if(s[i][j-1]==2) s[i][j]=3;
                if(s[i][j-1]==1) s[i][j]=2;
            }
        }
    }
    BFS();
    return 0;
}
/*
3
4
3 2 3
4 3 2 1 3
3 1

3
4
3 3 3
4 3 2 1 3
3 1
*/