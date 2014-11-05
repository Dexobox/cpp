#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int getOctal(int n){
  int oct=0;
  int mul=1;
  while(n>0){
    oct+=(n%8)*mul;
    mul*=10;
    n/=8;
  }
  return oct;
}

bool isPal(int n){
  stringstream ss;
  ss<<n;
  string str;
  ss>>str;
  string revStr = str;
  reverse(revStr.begin(),revStr.end());
  if(str==revStr) return true;
  return false;
}

int main(){
  int lo=1;
  int hi=100000;
  for(int i=lo;i<=hi;i++){
    int octal = getOctal(i);
    if(isPal(i)&&isPal(octal)){
      cout<<i<<" "<<octal<<endl;
    }
  }
  return 0;
}