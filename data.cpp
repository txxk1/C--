#include <bits/stdc++.h>

using namespace std;
int asd;
int third;
int main(){
    freopen("qwq.in","w",stdout);
    srand((int)time(0));
    int T=100;
    cout <<T<<endl;
    while(T--){
        int n=rand()%100+1;
        cout <<n<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x=rand()%2;
                if(x==0) cout <<'.';
                else cout <<"#";
            }
            cout <<endl;
        }
    }
    return 0;
}