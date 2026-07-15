#include <bits/stdc++.h>

using namespace std;
int T,n,k;
void solve() {
	cin >>n;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            int x=j,y=(i+j)%n,now;
            if(y==0) y=n;
            cout <<x<<" "<<y<<endl;
            cin >>now;

            if(now) return ;
        }
    }
}
int main() {
	cin >>T;
	while(T--) solve();
	return 0;
}