#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t -- ){
        long long n , m , p = 0;
        long long xx = 0, yy = 0;
        cin >> n >> m;
        if((n * (n + 1) / 2 * m * (m + 1) / 2 )% 2){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        if(2 * n * m - 3 == n * (n + 1) * m * (m + 1) / 8){
            for(int i = 1 ; i <= n ; i ++ ){
                for(int j = 1 ; j <= m ; j ++){
                    if(i == 1 && j == 1){
                        cout << 1 << " ";
                    }else if(i == n && j == m){
                     cout << 1 << " ";
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
            continue;
        }
        for(int i = 1 ; i < n ; i ++ ){
            for(int j = 1 ; j < m ; j ++){
                if(j == 1 && i == 1){
                    continue;
                }
                if(j == m && i == n){
                    continue;
                }
                long long x = n - i + 1 ;
                long long y = m - j + 1;
                long long pp = 3;
                if(x) pp++;if(y) pp++;
                if(2 * n * m + (i - 1 ) * (x - 1) * (j - 1) * (y - 1) - i * j - x * y + 1 ==  n * (n + 1) * m * (m + 1 ) / 8){
                    xx=i , yy = j;
                    p = 1 ;
                    break;
                }    
            }
            if(p){
                   break;
           }
        }
        for(int i = 1 ; i <= n ; i ++ ){
            for(int j = 1 ; j <= m ; j ++){
                if(i == n && j == m){
                    cout << 1 << " ";
                }else if(i == 1 && j == 1){
                    cout << 1 << " ";
                }else if(i == xx && j == yy){
                    cout << 1 << " ";
                }else{
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
}