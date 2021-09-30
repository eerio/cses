#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;

  multiset<int> tickets;
  int h;
  for (int i=0;i<n;++i) { cin >> h; tickets.insert(h); }

  int budget;
  for (int i=0; i < m; ++i) {
    cin >> budget;

    if (tickets.empty()) { cout << -1 << endl; continue; }
    
    multiset<int>::iterator it = tickets.lower_bound(budget);
    if (it == tickets.begin() && *it > budget) { cout << -1 << endl; }
    else if (*it == budget) { cout << *it << endl; tickets.erase(it); }
    else { cout << *prev(it) << endl; tickets.erase(prev(it)); }
  }
}
