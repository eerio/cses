#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool second_ascending(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> movies;
    int start,end;
    for (int i=0;i<n;++i) { cin >> start >> end; movies.push_back(make_pair(start, end));}

    sort(movies.begin(), movies.end(), second_ascending);

    // 35, 58, 49

    // dp[i] = best number we could get before with watching ith movie
    int dp[n];

    for (int i=0; i < n; ++i) {
        start = movies[i].first;
        end = movies[i].second;

        auto last_possible = prev(upper_bound(movies.begin(), movies.end(), start, second_ascending));
        int last_possible_ind = dist(movies.begin(), last_possible);
        dp[i] = max(dp, dp + last_possible_ind + 1);
    }

    return max(dp[n - 1], max(dp, dp + n - 1));
}