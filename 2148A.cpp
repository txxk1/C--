#include <bits/stdc++.h>

using namespace std;
int T,n,k;
int main(){
    cin >>T;
    while(T--){
        cin >>n>>k;
        cout <<n*(k%2)<<endl;
    }
    return 0;
}