#include <bits/stdc++.h>

using namespace std;
int s,a,b,x;
int main(){
    cin >>s>>a>>b>>x;
    int T=x/(a+b);
    int ans=T*a*s;
    int res=x-T*(a+b);
    ans+=min(a,res)*s;
    cout <<ans;
    return 0;
}