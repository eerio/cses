#include<bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int cnt = 0;

  char best;

  while (n) {
    best = 0;
    for (char c: to_string(n)) best = max(best, c);
    n -= best - '0';
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}
