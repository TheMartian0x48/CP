// @author: the__martian
// 10503
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;

vector<pii> data(20), v(20);
vi used(20, 0);
int n, q;
bool sol;

void dfs(int j = 1) {
  if (j == n + 1) {
    sol |= v[n + 1].first == v[n].second;
    return;
  }

  rep(k,0,q) {
    if (!used[k] && v[j-1].second == data[k].first) {
      used[k] = 1;
      v[j] = data[k];
      dfs(j + 1);
      used[k] = 0;
    }
    if(sol) return;
    if (!used[k] && v[j-1].second == data[k].second) {
      used[k] = 1;
      v[j] = {data[k].second, data[k].first};
      dfs(j + 1);
      used[k] = 0;
    }
    if(sol) return;
  } 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  while (cin >> n, n) {
    cin >> q;
    cin >> v[0].first >> v[0].second;
    cin >> v[n+1].first >> v[n+1].second;
    rep(i,0,q) {
      cin >> data[i].first >> data[i].second;
    }
    sol = false;
    rep(i,0,20) used[i] = 0;
    dfs();
    cout << (sol ? "YES\n" : "NO\n");
  }
}