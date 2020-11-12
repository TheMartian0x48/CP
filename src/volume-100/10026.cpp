// author : the__martian
// 10026 
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

bool cmp(const pair<pair<int, int>, int>&a, const pair<pair<int, int>, int>&b) {
  ll n1 = a.first.first * b.first.second;
  ll n2 = b.first.first * a.first.second;
  if (n1 > n2) return true;
  if (n1 == n2) return a.second > b.second;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int tests; cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++) {
      double a, b; cin >> a >> b;
      v[i].first = {a, b};
      v[i].second = i + 1;
    }
    sort(v.rbegin(), v.rend(), cmp);
    for (int i = 0; i < n; i++) {
      if (i)
        cout << " ";
      cout << v[i].second;      
    }
    cout << "\n";
    if (test != tests)
      cout << "\n";
  }
}
