#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i=0;i<n;++i)cin>>x[i];

  sort(x.begin(), x.end());

  int prev=-1, cnt=0;
  for (int i=0;i<n;++i) {
    if (x[i] == prev) continue;
    cnt++;
    prev=x[i];
  }

  cout << cnt << endl;

  return 0;
}
