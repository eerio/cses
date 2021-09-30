#include<bits/stdc++.h>
using namespace std;

#define MOD (1000000007U)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  
  int c[n];
  for (int i=0; i < n; ++i) cin >> c[i];
  sort(c, c + n);

  unsigned int dp[x + 1] = {1};

  for (int i=1; i <= x; ++i) {
    for (int j=0; j < n; ++j) {
      dp[i] += i >= c[j] ? dp[i - c[j]] : 0;
      dp[i] %= MOD;
    }
  }

  cout << dp[x] << endl;

  return 0;
}
