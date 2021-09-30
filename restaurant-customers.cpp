#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int n, start, end;
  cin >> n;

  vector<pair<int, int>> intervals;

  for (int i=0; i < n; ++i) {
    cin >> start >> end;
    intervals.push_back(make_pair(start, end));
  }

  sort(intervals.begin(), intervals.end(), [](auto &l, auto &r){ return l.second < r.second; });

  for (int i=0;i<n;++i) cout << intervals[i].first << ' ' << intervals[i].second << endl;
}
