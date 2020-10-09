
// author : the__martian
// 10338
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

unordered_map<char, pair<int, int>> mp;

unsigned long long solve(int n){
  unsigned long long tmp = 1;
  int mi = min(11, n);
  for (int i = 1; i <= mi; i++) {
    tmp *= i;
  }
  for (auto &p : mp){
    auto &c = p.second;
    while(tmp % c.first == 0 && c.first <= c.second){
      tmp /= c.first;
      c.first++;
    }
  }
  for (int i = 12; i <= n; i++) {
    tmp *= i;
    for (auto &p : mp){
    auto &c = p.second;
      while(tmp % c.first == 0 && c.first <= c.second){
        tmp /= c.first;
        c.first++;
      }
    }
  }
  return tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int test; cin >> test;
  int tt = 1;
  while (test--){
    cout << "Data set " << tt++ << ": ";
    string s; cin >> s;
    for (auto c : s){
      mp[c].second++;
      mp[c].first = 2;
    }
    unsigned long long res = solve(sz(s));
    cout << res << "\n";
    mp.clear();
  }
}