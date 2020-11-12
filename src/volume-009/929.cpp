// author : the__martian
// 929
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

vector<vi> v(1005, vi(1005)), dis(1005, vi(1005));
int n, m;
vi dr{-1, 0, 1, 0}, dc{0, 1, 0, -1};

bool valid(int r, int c) {
  return r >= 0 && c >= 0 && r < n && c < m;
}

int solve() {

  rep(i,0,n) {
    rep(j,0,m) {
      dis[i][j] = INT_MAX;
    }
  }
  dis[0][0] = v[0][0];
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push({-dis[0][0], {0,0}});
  while(pq.size()) {
    int d = pq.top().first * -1;
    int r = pq.top().second.first;
    int c = pq.top().second.second;
    pq.pop();
    if (d != dis[r][c]) {
      continue;
    }
    for (int i = 0; i < 4; i++) {
      int rr = r + dr[i];
      int cc = c + dc[i];
      if (valid(rr, cc) && d + v[rr][cc] < dis[rr][cc]) {
        dis[rr][cc] = d + v[rr][cc];
        pq.push({-dis[rr][cc], {rr, cc}});
      }
    }
  }
  return dis[n - 1][m - 1];
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);



  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    rep(i,0,n) {
      rep(j,0,m) {
        cin >> v[i][j];
      }
    }
    cout << solve() << "\n";
  }
}
