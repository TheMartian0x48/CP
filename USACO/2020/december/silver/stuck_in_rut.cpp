#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

bool cmpx(const pair<pii, int>&a, const pair<pii, int>&b) {
  return a.first.first < b.first.first;
}
bool cmpy(const pair<pii, int>&a, const pair<pii, int>&b) {
  return a.first.second < b.first.second;
}

int main() {
  int n; cin >> n;
  vector<pair<pii, int>> east,north;
  for (int i = 0; i < n; i++) {
    char ch; cin >> ch; int x, y; cin >> x >> y;
    ch == 'N' ? north.push_back({{x, y},i}) : 
      east.push_back({{x, y}, i});
  }

  sort(east.begin(), east.end(), cmpy);
  sort(north.begin(), north.end(), cmpx);
  int l1 = east.size(), l2 = north.size();
  vector<int> res(n, 0);
  vector<bool> stope(l1, false), stopn(l2, false);
  for (int i = 0; i < l1; i++) {
    for (int j = 0; j < l2; j++) {
      if (!stope[i] && !stopn[j] && east[i].first.second > north[j].first.second &&
        east[i].first.first < north[j].first.first) {
          int t1 = north[j].first.first - east[i].first.first;
          int t2 = east[i].first.second - north[j].first.second;
          if (t1 < t2) {
            stopn[j] = true;
            res[east[i].second] += 1 + res[north[j].second];
          } else if (t1 > t2){
            stope[i] = true;
            res[north[j].second] += 1 + res[east[i].second];
          }
      }
    }
  }
  for (auto a : res) cout << a << "\n";
}