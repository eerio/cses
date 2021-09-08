#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int xs[n];
  for (int i=0; i < n; ++i) cin >> xs[i];

  // bool: 0 = cut left end, 1 = cut right end
  int dp[n + 1][n + 1] = {0};
  bool dir[n + 1][n + 1] = {0};
  
  for (int off=1; off < n + 1; ++off) {
    for (int t=0; off + t < n + 1; ++t) {
      // try cut left
      int cut = xs[t];
      int whats_left_after_opponent = dir[t + 1][off + t] 
        ? dp[t + 1][off + t - 1]
        : dp[t + 2][off + t - 1];

      int score_cut_left = cut + whats_left_after_opponent;

      // try cut right
      cut = xs[off + t - 1];
      whats_left_after_opponent = dir[t][off + t - 1]
        ? dp[t][off + t - 2]
        : dp[t + 1][off + t - 1];

      int score_cut_right = cut + whats_left_after_opponent;

      if (score_cut_left >= score_cut_right) {
        dp[t][off + t] = score_cut_left;
        dir[t][off + t] = 0;
      } else {
        dp[t][off + t] = score_cut_right;
        dir[t][off + t] = 1;
      }
    }
  }

  cout << dp[0][n] << endl;
  return 0;
}
