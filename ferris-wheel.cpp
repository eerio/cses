#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,x;
  cin>>n>>x;
  int p[n],cnt=0;
  for (int i=0;i<n;++i) cin>>p[i];
  
  sort(p,p+n);
  
  int l=0, r=n-1;

  while (l < r) {
    if (p[l] + p[r] <= x) {l++;r--;cnt++;}
    else {r--; cnt++;}
  }
  if (l==r) cnt++;

  cout<<cnt<<endl;
}
