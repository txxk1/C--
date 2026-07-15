#include <bits/stdc++.h>
#define int long long 
using namespace std;
int T,n;
int a[3005],c[3005],b[3005],Q[3005];
inline int read(){
    int s=0ll,f=1ll;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return s*f;
}
int maxn(int x,int y){
    if(x<y) return y;
    return x;
}
int m,u,v,w,cnt,head[3005];
struct node{
	int to,nxt;
}e[6000005];
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int dfn[3005],low[3005],dfncnt,bb[6000005],cc[3005],dcc;
vector<int> ans[3005];
void tarjan(int x,int edge){
	dfn[x]=low[x]=++dfncnt;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(dfn[y]==0){
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x]){
				bb[i]=bb[i^1]=1;
				
			}
		}
		else if(i!=(edge^1)){
			low[x]=min(low[x],dfn[y]);
		}
	}
}
void dfs(int x){
	cc[x]=dcc;
	if(x) ans[dcc].push_back(x);
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(cc[y]||bb[i]) continue;
		dfs(y);
	}
}
void solve(){
    n=read();
    dfncnt=0;
    cnt=1;
    dcc=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        b[i]=read();
        c[i]=read();
        head[i]=0;
        dfn[i]=0;
        low[i]=0;
        ans[i].clear();
        cc[i]=0;
        Q[i]=0;
    }

    cc[0]=0;

    for(int i=0;i<=2*n*n;i++){
        bb[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x=a[i]-a[j],y=b[i]-b[j],z=c[i]-c[j];
            if(x==0){
                if(y!=0){
                    continue;
                }
                else{
                    if(z!=0){
                        //cout <<i<<" "<<j<<endl;
                        add(i,j);
                        add(j,i);
                    }
                }
            }
            else if(y*y<4ll*x*z){
                //cout <<i<<" "<<j<<endl;
                add(i,j);
                add(j,i);
            }
        }
    }
    for(int i=1;i<=n;i++){
		if(dfn[i]==0) tarjan(i,0);
	}
	for(int i=1;i<=n;i++){
		if(cc[i]==0){
			dcc++;
			dfs(i);
		}
	}
	//cout <<dcc<<endl;
	for(int i=1;i<=dcc;i++){
		for(int j=0;j<ans[i].size();j++){
			int now=ans[i][j];
            
            Q[now]=maxn(Q[now],ans[i].size());
		}
	}
    for(int i=1;i<=n;i++) cout <<Q[i]<<" ";
    cout <<endl;
    return ;
}
signed main(){
    T=read();
    while(T--) solve();
    return 0;
}