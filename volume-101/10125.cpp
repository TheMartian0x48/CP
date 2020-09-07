// @author:   the__martian
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

struct ele{
  ll sum, x, y;
  friend bool operator<(const ele& a, const ele&b) {
    return a.sum < b.sum || (a.sum == b.sum && a.x < b.x) 
      || (a.sum == b.sum && a.x == b.x && a.y < b.y);
  }
};

vector<ele> arr(1000100);
vector<ll> v(1005);
int n, idx;

bool search(ll s, ll x, ll y) {

  int l = 0, r = idx, m;
  while (l + 1 < r) {
    m = l + (r - l) / 2;
    if (arr[m].sum > s)
      r = m;
    else if (arr[m].sum == s) {
      rep(i,m,idx) {
        if (arr[i].sum != s) break;
        else if (arr[i].x == x || arr[i].y == y
          || arr[i].x == y || arr[i].y == x)
          continue;
        else  
          return true;
      }
      per(i,m,0) {
        if (arr[i].sum != s) break;
        else if (arr[i].x == x || arr[i].y == y
          || arr[i].x == y || arr[i].y == x)
          continue;
        else  
          return true;
      }
      return false;
    } else 
      l = m;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while (cin >> n, n) {
    rep(i,0,n) cin >> v[i];
    sort(v.begin(), v.begin() + n);

    idx = 0;
    rep(i,0,n) {
      rep(j, i + 1, n) {
        arr[idx].sum = v[i] + v[j];
        arr[idx].x = v[i];
        arr[idx].y = v[j];
        idx++;
      }
    }
    sort(arr.begin(), arr.begin() + idx);
    ll res = -1e15;
    bool sol = false;
    per(i,n - 1, 0){
      if (sol) break;
      rep (j,0,n) {
        if (i == j) continue;

        if (search(v[i] - v[j], v[i], v[j])) {
          res = v[i];
          sol = true;
          break;
        }
      }
    }
    if (sol) cout << res << endl;
    else cout << "no solution\n";
  }
}