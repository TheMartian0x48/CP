
// author : the__martian
// 11348
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  vi stamps(10005), cnt(55);
  vector<vi> person(55);
  int tests; cin>> tests;
  for (int test = 1; test <= tests; test++){
    printf("Case %d: ", test);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      int k; cin >> k;
      for (int j = 0, z; j < k; j++){
        cin >> z;
        person[i].push_back(z);
      }
      sort(all(person[i]));
      person[i].erase(unique(all(person[i])), person[i].end());
      for (auto j : person[i]){
        stamps[j]++;
      }
    }
    double total = 0;
    for (int i = 0; i < n; i++) {
      for (auto j : person[i]) {
        cnt[i] += stamps[j] == 1;
      }
      total += cnt[i];
    }
    if (total == 0) {
      printf("\n");
      for (int i = 0; i < n; i++) {
        cnt[i] = 0, person[i].clear();
      }
      stamps.assign(10005, 0);
      continue;
    }
    double fact = 100 / total;
    for (int i = 0; i < n; i++) {
      double per = fact * cnt[i];
      printf("%.6lf%%", per);
      if (i != n - 1)
        printf(" ");
      cnt[i] = 0;
      person[i].clear();
    }
    stamps.assign(10005, 0);
    printf("\n");
  }
}