#include <bits/stdc++.h>

using namespace std;
int n,m,u,v,w,cnt=1,head[500005];
struct node{
	int to,nxt;
}e[4000005];
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int dfn[500005],low[500005],dfncnt,b[4000005],c[500005],dcc;
vector<int> ans[500005];
void tarjan(int x,int edge){
	dfn[x]=low[x]=++dfncnt;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(dfn[y]==0){
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x]){
				b[i]=b[i^1]=1;
				
			}
		}
		else if(i!=(edge^1)){
			low[x]=min(low[x],dfn[y]);
		}
	}
}
void dfs(int x){
	c[x]=dcc;
	if(x) ans[dcc].push_back(x);
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(c[y]||b[i]) continue;
		dfs(y);
	}
}
int main(){
	cin >>n>>m;
	for(int i=1;i<=m;i++){
		cin >>u>>v;
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]==0) tarjan(i,0);
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			dcc++;
			dfs(i);
		}
	}
	cout <<dcc<<endl;
	for(int i=1;i<=dcc;i++){
		cout <<ans[i].size();
		for(int j=0;j<ans[i].size();j++){
			cout <<" "<<ans[i][j];
		}
		cout <<endl;
	}
	return 0;
} 