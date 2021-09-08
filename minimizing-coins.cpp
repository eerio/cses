#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  
  int c[n];
  for (int i=0; i < n; ++i) cin >> c[i];

  unsigned int dp[x + 1];
  memset(dp, UINT_MAX, sizeof(dp)); 
  for (int i=0; i < x + 1; ++i) {
    assert(dp[i] == UINT_MAX);
  }

  dp[0] = 0;

  unsigned int best;
  for (int i=1; i <= x; ++i) {
    best = UINT_MAX;
    for (int j=0; j < n; ++j)
      best = min(best, i >= c[j] ? dp[i - c[j]] : UINT_MAX);

    if (best < UINT_MAX) dp[i] = best + 1;
  }

  cout << (int)(dp[x] < UINT_MAX ? dp[x] : -1) << endl;

  return 0;
}
