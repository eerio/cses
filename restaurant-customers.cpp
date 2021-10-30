#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int n, start, end;
  cin >> n;

  vector<int> starts, ends;

  for (int i=0; i < n; ++i) {
    cin >> start >> end;
    starts.push_back(start);
    ends.push_back(end);
  }

  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());

  int best=0, i=0, j=0, current=0;

  while (i < n && j < n) {
    if (starts[i] < ends[j]) {
      current++;
      i++;
      best = max(best, current);
    } else if (starts[i] == ends[i]) {
      i++; j++;
    } else {
      current--;
      j++;
    }
  }

  while (i < n) current++;
  best = max(best, current);

  cout << best << endl;
  return 0;
}
