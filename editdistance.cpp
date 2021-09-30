#include<bits/stdc++.h>
#define MOD (1000000007U)
#define FOR_i(a) (for (int i=0; i < a; ++i))
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();

  int dp[n + 1][m + 1];
  memset(dp, INT_MAX, sizeof(dp));

  for (int i=0; i < n + 1; ++i) dp[i][0] = i;
  for (int i=0; i < m + 1; ++i) dp[0][i] = i;

  int dist;
  for (int i=1; i < n + 1; ++i) {
    for (int j=1; j < m + 1; ++j) {
      if (a[n - i] == b[m - j]) dist = dp[i - 1][j - 1];
      else dist = 1 + min({
          dp[i][j - 1],
          dp[i - 1][j],
          dp[i - 1][j - 1]
      });

      dp[i][j] = dist;
    }
  }
/*
  for (int i=0;i<n+1;++i){for(int j=0;j<m+1; ++j) {
    cout << dp[i][j];
  }cout<<endl;}
*/
  cout << dp[n][m] << endl;
  return 0;
}
