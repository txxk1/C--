#include<bits/stdc++.h>
using namespace std;
int a[2000500];
int org[2000500];
bool p[1000500];
signed main(){
    int n , loc = 1;
    cin >> n;
    for(int i = 1 ; i <= 2 * n + 2 ; i ++ ){
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; i ++ ){
        org[i] = a[2 * n + 2] / 2 - 1;
    }
    for(int i = 1 ; i <= n ; i ++ ){
        if(org[i] < i && org[i] < n - i + 1){
            p[i + org[i] + 1] = !p[i - org[i] - 1];
            while(loc <= i + org[i]){
                if(loc >= i - org[i] && p[2 * i - loc])
                    p[loc] = p[2 * i - loc];
                loc ++;
            }
        }
    }
    for(int i = 1 ; i <= n ; i ++ ){
        if(p[i]){
            cout << "a" ;
        }else{
            cout << "b" ;
        }
    }
    return 0;
}