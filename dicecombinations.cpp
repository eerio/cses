#include<bits/stdc++.h>
using namespace std;
#define MOD (1000000007U)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int dp[n + 1] = {1};

  int sum;
  for (int i=1; i <= n; ++i) {
    sum = 0;
    for (int j=1; j <= 6 && i - j >=0; ++j) {
      sum += dp[i - j];
      sum %= MOD;
    }

    dp[i] = sum;
  }


  cout << dp[n] << endl;

  return 0;
}

