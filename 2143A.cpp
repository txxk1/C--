#include<bits/stdc++.h>
using namespace std;
int t , n , a[500] , l , r , minx; 
int main(){
    cin >> t;
    for(int p = 1 ; p <= t ; p ++ ){
        cin >> n;
        for(int i = 1 ; i <= n ; i ++ ){
            cin >> a[i];
            if(a[i] == n){
                l = i , r = i , minx = n;
            }
        }
        int pd = 1;
        while(true){
            if( l == 1 && r == n){
                break;
            }
            if( l >= 1 && a[l - 1] == minx - 1){
                l--;
                minx--;
            }else if( r <= n && a[r + 1] == minx - 1){
                r ++;
                minx--;
            }else{
                cout << "no" << endl;
                pd = 0;
                break;
            }
        }
        if(pd == 1){
            cout << "yes" << endl;
        }
    }
}