#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[6];
int ans;
/*
void dfs(int c , int num){
    if(c == 5){
        if(num + a[5] == 6){
            ans ++ ;
        }else if(num + 1 == 6){
            ans ++ ;
        }
    }else if(num > 6){
        return ;
    }else{
        dfs(c + 1 , num + a[c]);
        dfs(c + 1 , num + 1);
    }

}
    */
signed main(){
    int t;
    cin >> t;
    while(t -- ){        
        for(int i = 1 ; i <= 5 ; i ++){
            cin >> a[i];
        }
        ans = 0;
        ans=min(a[1],a[5])+min(a[2],a[4])+a[3]/2;
        int p=min(a[1],a[5]),q=min(a[2],a[4]);
        a[5]-=p;
        a[1]-=p;
        a[2]-=q;
        a[4]-=q;
        a[3]=a[3]%2;
        if(a[5]){
            int last=a[3]+a[2]+a[4];
            if(a[5]>=last){
                ans+=last;
                a[5]-=last;
                ans+=a[5]/2;
            }
            else{
                ans+=a[3];
                a[5]-=a[3];
                ans+=a[5];
                int x=max(a[2],a[4]);
                x-=a[5];
                ans+=x/3;
            }
        }
        else if(a[1]){
            if(a[4]){
                if(a[1]>a[4]*2) {
                    ans+=a[4];
                    a[1]-=a[4]*2;
                    if(a[3] && a[1]>=3){
                        ans++;
                        a[1]-=3;
                    }
                    ans+=a[1]/6;
                }
                else{
                    int sum=a[1]+a[4];
                    ans+=sum/3;
                    a[4]-=sum/3;
                    a[1]=sum%3-a[4];
                    if(a[3]){
                        if(a[1]+a[4]>=2) {
                            ans++;
                        
                        }
                    }
                }
            }
            else if(a[2]){
                if(a[3] && a[1] && a[2]) {
                    ans++;
                    a[3]--,a[1]--,a[2]--;
                }
                ans+=a[2]/3;
                a[2]%=3;
                if(a[2]==2 && a[1]>=2) {
                    ans++;
                    a[1]-=2;
                    a[2]=0;
                }
                else if(a[2]==1){
                    if(a[1]>=4) {
                        ans++;
                        a[1]-=4;
                    }
                }
                ans+=a[1]/6;
            }
            else {
                if(a[3] && a[1]>=3){
                    ans++;
                    a[1]-=3;
                }
                ans+=a[1]/6;
            }
        }
        else if(!a[1] && !a[5]){
            if(a[2] || a[4]){
                int x=max(a[2],a[4]);
                ans+=x/3;
                x%=3;
                if(a[3] && x>=2){
                ans++;
                }
            }
        }
        cout << ans <<endl;
    }
}
/*
5
3 3 3 3 3
2 3 4 5 1
1 2 3 4 5
2 2 0 0 0
0 3 0 0 3
*/