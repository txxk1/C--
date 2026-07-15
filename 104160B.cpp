#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int i = 1;
    int m = 0;
    while(m < n){
        cout << 0;
        m ++;
        for(int j = 1 ; j <= min(i , n - m) ; j ++ ){
            cout << 1;
        }
        m += i;
        i ++;
    }
}