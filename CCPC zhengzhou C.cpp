#include <bits/stdc++.h>

using namespace std;
int A,B,x,y,a,b,debug;
int crossx=1,crossy=1;
int powx=0,powy=0,ans=0;
int xx[105],yy[105],cnt;
int main(){
    cin >>A>>B;
    cin >>x>>y;
    if(A==x&&B==y){
        cout <<0<<endl;
        return 0;
    }
    a=A;
    b=B;
    while(a%2==0&&a!=0) a=a/2,crossx*=2,powx++;
    while(b%2==0&&b!=0) b=b/2,crossy*=2,powy++;
    if(a==0) debug++;
    else if(x%a!=0){
        cout <<-1<<endl;
        return 0;
    }
    if(b==0) debug++;
    else if(y%b!=0){
        cout <<-1<<endl;
        return 0;
    }
    A=A/a;
    x=x/a;
    B=B/b;
    y=y/b;
    int sx=x,sy=y,px=0,py=0;
    while(sx%2==0&&sx!=0) sx=sx/2,px++;
    while(sy%2==0&&sy!=0) sy=sy/2,py++;
    int needx=powx-px,needy=powy-py;
    ans=min(needx,needy)+(max(needx,needy)-min(needx,needy))*min(needx,needy);
    cout <<ans<<endl;
    xx[1]=0;
    yy[1]=0;
    xx[2]=A;
    yy[2]=B;
    int xl=0,xr=A,yl=0,yr=B,xmid,ymid;
    for(int i=1;i<=min(powx-sx,powy-sy);i++){
        cout <<xl*crossx<<" "<<yl*crossy<<" "<<xr*crossx<<" "<<yr*crossy<<endl;
        xmid=(xl+xr)/2,ymid=(yl+yr)/2;
        if(xmid<x) xl=xmid;
        else xr=xmid;
        if(ymid<y) yl=ymid;
        else yr=ymid; 
    }

    return 0;
}
/*
5 2    5 3


4 4    4 4
6 2    6 2
4 0
4 2

4 2

*/