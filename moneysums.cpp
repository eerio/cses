#include<array>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

// time: O(n * sum(x_i)), space: O(sum(x_i))
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  int xs[n];
  int s = 0;
  for (int i=0; i < n; ++i) {
    cin >> xs[i];
    s += xs[i];
  }

  bool results[s + 1]={true}, results2[s + 1];
  for (int coin: xs) {
    copy(results, results + (s + 1), results2);
    for (int i=0; i < s + 1; ++i) {
      if (results2[i]) results[i + coin] = true;
    }
  }

  int result = 0;
  for (int i=1; i < s + 1; ++i) if (results[i]) result++;
  cout << result << endl;

  int i = 1;
  for (; i < s + 1; ++i) {
    if (results[i]) { cout << i; break; }
  }
  ++i;

  for (; i < s + 1; ++i) {
    if (results[i]) cout << ' ' << i;
  }
  cout << endl;
  return 0;
}

