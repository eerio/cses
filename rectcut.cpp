#include<bits/stdc++.h>
using namespace std;

// time: O(ab(a + b)), space: O(ab)
int solution(int a, int b) {
  int dp[a + 1][b + 1];
  memset(dp, INT_MAX, sizeof(dp));

  for (int y=1; y <= a; ++y) {
    for (int x=1; x <= b; ++x) {
      if (x == y) {
        dp[y][x] = 0;
        continue;
      }

      int min_vertical = INT_MAX;
      for (int y2=1; y2 <= y / 2; ++y2) {
        min_vertical = min(min_vertical, dp[y2][x] + dp[y - y2][x]);
      }

      int min_horizontal = INT_MAX;
      for (int x2=1; x2 <= x / 2; ++x2) {
        min_horizontal = min(min_horizontal, dp[y][x2] + dp[y][x - x2]);
      }

      dp[y][x] = 1 + min(min_vertical, min_horizontal);
    }
  }

  return dp[a][b];
}


int main() {
  int a, b;
  cin >> a >> b;

  cout << solution(a, b) << endl;
  return 0;
}

