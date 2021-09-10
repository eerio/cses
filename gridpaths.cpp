#include<bits/stdc++.h>
using namespace std;
#define MOD (1000000007U)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  //vector< vector<int> > dp(n + 1, vector<int> (n + 1));
  int dp[n + 1][n + 1] = {};
  dp[0][1] = 1;
/*
  cout<<"Grid:"<<endl;

  for (int i=0; i < n + 1; ++i) {
    for (int j=0; j < n + 1; ++j) {
      cout << dp[i][j] << ' ';
    }
    
    cout<< endl;
  }
  cout <<"end."<<endl;

  return 0;
*/
  string row;
  for (int y=1; y < n + 1; ++y) {
    cin >> row;
    for (int x=1; x < n + 1; ++x) {
//      cout << x << ' ' << y << ' '<< dp[y-1][x] <<' ' << dp[y][x-1]<<endl;
      if (row[x - 1] == '*') {
        dp[y][x] = 0;
      } else {
        dp[y][x] = (dp[y - 1][x] + dp[y][x - 1]) % MOD;
      }
/*
cout << "Grid:" << endl;
  for (int i=0;i<n+1;++i) {
    for (int j=0;j<n+1;++j) {
      cout << dp[i][j] << ' ';
    }cout<< endl;
  }
*/

    }
  }

  cout << dp[n][n] << endl;

  return 0;
}
