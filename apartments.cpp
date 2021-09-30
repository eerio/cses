#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  int a[n], b[m];
  for (int i=0;i<n;++i) cin>>a[i];
  for (int i=0;i<m;++i) cin>>b[i];
  sort(a,a+n);
  sort(b,b+m);

  int i=0, j=0, cnt=0, request, area;

  while (i < n && j < m) {
    request = a[i];
    area = b[j];
    
    if (request < area - k) i++;
    else if (request > area + k) j++;
    else {
      i++; j++; cnt++;
    }
  }
  
  cout << cnt << endl;
}
