#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int counter;
int printperm(string s,int n,string d,int l) {
  if(d.length() == l) {
    cout<<d<<" ";
    counter++;
    return 0;
  }
  if(n==0) {
   
    return 0;
  }

  else {
    for(int i=0;i<s.length();i++) {     
      string t = d+s[i];
      string p = s;
      printperm(p.erase(i,1), n-1,t,l);

    }
  }
  return 0;
}



int main() {
   string s;
   cin>>s;
   printperm(s,s.length(),"",s.length());
   cout<<"\n"<<counter;
}