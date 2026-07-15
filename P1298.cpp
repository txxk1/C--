#include <iostream>
#include <cstring>
using namespace std;
int n,m,an,am,flag;
int ansn,ansm;
int gcd(int n,int m){
	if(m==0) return n;
	else return gcd(m,n%m);
}
double ans,eps;
int main(){
    cin >>n>>m;
    cin >>ans;
    an=0,am=1;
    eps=10000000.00;
    while(am<=m){
        while((double)an/am-ans<1e-15&&an<=n){
            if(eps+(double)an/am-ans>1e-15){
                eps=ans-(double)an/am;
                ansn=an;
                ansm=am;
				flag=0;
            }
			
            an++;
        }
		if(gcd(an,am)==1&&(double)an/am-ans-eps<1e-15&&(double)an/am-ans-eps>-1e-15) flag=1;
        if((double)an/am-ans-eps<1e-15&&an<=n){
            eps=(double)an/am-ans;
            ansn=an;
            ansm=am;
        }
		
        am++;
    }
	if(flag){
		cout <<"TOO MANY";
		return 0;
	}
    cout <<ansn/gcd(ansn,ansm)<<"/"<<ansm/gcd(ansn,ansm);
    return 0;
}