#include <iostream>
using namespace std;
string a;
int main()
{
  cin >>a;
  for(int i=0;i<a.size();i++){
    if(a[i]<='9'&&a[i]>='0') cout <<"Q";
    if(a[i]>='a'&&a[i]<='z') cout <<"L";
  }
  return 0;
}