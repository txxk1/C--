#include <bits/stdc++.h>

using namespace std;
int S,T,p[20],vis[1<<18];
int al[5]={1,-1,0,0};
int ar[5]={0,0,1,-1};
struct node{
    int x,dep;
};
queue <node> Q;
int main(){
    p[0]=1;
    p[1]=2;
    for(int i=2;i<=18;i++) p[i]=p[i-1]*2;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            char ch=getchar();
            while(ch<'0'||ch>'9') ch=getchar();
            if(ch=='1') S+=p[i*4+j];
        }
        char ch=getchar();
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            char ch=getchar();
            while(ch<'0'||ch>'9') ch=getchar();
            if(ch=='1') T+=p[i*4+j];
        }
        char ch=getchar();
    }
    //cout <<S<<" "<<T<<endl;
    Q.push((node){S,0});
    vis[S]=1;
    while(!Q.empty()){
        int now=Q.front().dep,s=Q.front().x;
        Q.pop();
        //cout <<s<<endl;
        if(s==T){
            cout <<now;
            return 0;
        }
        for(int i=0;i<16;i++){
            if((s&(1<<i))!=0){
                //cout <<(s&(1<<i) )<<endl;
                int x=i/4,y=i%4;
                for(int k=0;k<4;k++){
                    if(x+al[k]>=0&&x+al[k]<4&&y+ar[k]>=0&&y+ar[k]<4){
                        int qwq=(x+al[k])*4+y+ar[k];
                        if((s&p[qwq])==0&&!vis[s-p[i]+p[qwq]]) vis[s-p[i]+p[qwq]]=1,Q.push((node){s-p[i]+p[qwq],now+1});
                    }
                }
            }
        }
    }
    return 0;
}