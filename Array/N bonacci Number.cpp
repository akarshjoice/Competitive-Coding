// Question:
/*
Print first m ,N-bonacci numbers

Input : N=3, m=8
Output: 0 0 1 1 2 4 7 13
*/


// Code:

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector <int> a;
  for(int i=1;i<=(n-1);i++) {
    //cout<<"0"<<" ";
    a.push_back(0);
  }
  //cout<<"1"<<" ";
  int sum=1;
  a.push_back(1);
  int j=0;
  for(int i=n+1;i<=m;i++) {
    a.push_back(sum);
    sum+=sum-a[j];
    j++;
  }
  for(int i=0;i<a.size();i++) {
    cout<<a[i]<<" ";
  }
}