#include<iostream>
//#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int n, x, t;
  cin >> n >> x;
  vector<pair<int, int>> a;
  for (int i=0;i<n;++i) { cin >> t; a.push_back(make_pair(t, i)); };
/*
  unordered_map<int, int> visited;

  for (int i=0; i < n; ++i) {
    int num = a[i];
    int complement = x - num;

    auto it = visited.find(complement);
    if (it == visited.end()) {
      visited.insert({num, i});
    } else {
      cout << it->second + 1<< ' ' << i + 1<< endl;
      return 0;
    }
  }
*/
  //for (int i=0;i<n;++i) cout << a[i].first << ' ' << a[i].second << endl;
  sort(a.begin(), a.end(), [](auto &l, auto &r){ return l.first < r.first; });
  //for (int i=0;i<n;++i) cout << a[i].first << ' ' << a[i].second << endl;


  int l = 0, r = n - 1;
  while (l < r) {
    if (a[l].first + a[r].first == x) {
      cout << a[l].second + 1 << ' ' << a[r].second + 1 << endl;
      return 0; 
    }
    else if (a[l].first + a[r].first < x) { l++; }
    else { r--; }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
