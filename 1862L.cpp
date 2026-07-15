#include<bits/stdc++.h>
using namespace std;
struct hg{
    int tm , num;
}q[100500] , h[100500];
bool cmp(hg x , hg y){
    return x.tm < y.tm;
}
int main(){
    int n , cnt1 = 0 , cnt2 = 0 ;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++ ){
        int a , b ,  c , d;
        cin >> a >> b >> c >> d;
        if(c && d){
            if(a > b){
                cnt2 ++;
                h[cnt2].num = i;
                h[cnt2].tm = b;
            }else{
                cnt1 ++;
                q[cnt1].num = i;
                q[cnt1].tm = a;
            }
        }else if(c){
            cnt1 ++;
            q[cnt1].num = i;
            q[cnt1].tm = a;
        }else{
            cnt2 ++;
            h[cnt2].num = i;
            h[cnt2].tm = b;
        }
    }
    sort(q + 1 , q + 1 + cnt1 , cmp);
    sort(h + 1 , h + 1 + cnt2 , cmp);
    cout << cnt1 << " ";
    for(int i = 1 ; i <= cnt1 ; i ++ ){
        cout << q[i].num  << " ";
    }
    cout << endl;
    cout << cnt2 << " ";
    for(int i = 1 ; i <= cnt2 ; i ++ ){
        cout << h[i].num  << " ";
    }
    cout << endl;
    return 0;
}