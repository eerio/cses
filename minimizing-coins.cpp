#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  int c[n];

  cin >> n >> x;
  for (int i=0; i < n; ++i) cin >> c[i];

  int dp[x + 1] = {1};

  int best;
  for (int i=1; i <= x; ++i) {
    for (int j=0; j < n; ++j) best = min(best, dp[i - c[j]]);
    dp[i] = best + 1;
  }

  cout << dp[n] << endl;
  return 0;
}
