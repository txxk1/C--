#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,sum,f,qwq;
inline int read(){
    int s=0,f=1;
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
void solve(){
    cin >>n;
    cout <<"? "<<1<<" "<<n<<endl;
    cin >>sum;
    int flag=1,L=1,R=n;
    while(flag){
        int qwq=0;
        int l=L,r=R,now;
        while(l<r){
            int mid=(l+r)/2;
            cout <<"? "<<L<<" "<<mid<<endl;
            cin >>now;
            if(now<sum/2ll) l=mid+1;
            else r=mid-1;
        }
        for(int i=min(R,l+1);i>=max(l-1,L);i--){
            cout <<"? "<<L<<" "<<i<<endl;
            cin >>now;
            if(now==sum/2ll) qwq=i;
        } 
        if(qwq==0) flag=0;
        else{
            sum=sum/2;
            if(qwq-L>R-qwq-1){
                L=qwq+1;
            }
            else R=qwq;
        }
    }
    cout <<"! "<<sum<<endl;
    return ;
}
signed main(){
    cin >>T;
    while(T--) solve();
    return 0;
}
// ffffttttt
//  l  x  mid   r
//  2 2 4 2 1 1 2 2