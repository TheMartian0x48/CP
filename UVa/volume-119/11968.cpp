/*
 * TheMartian0x48
 * UVa 11968.cpp
 */
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
// clang-format on

vector<double> drink(1005), cake(1005);

void solve() {
  int n; cin >> n;
  int m, k; cin >> m >> k;
  double avg = 0;
  rep(i,0,m) cin >> cake[i], avg += cake[i];
  rep(i,0,k) cin >> drink[i], avg += drink[i];
  rep(i,0,n - k - m) {
    int t;
    cin >> t;
    avg += t;
  }
  sort(drink.begin(), drink.begin() + k);
  sort(cake.begin(), cake.begin() + m);
  avg /= n;
  int id1 = upper_bound(drink.begin(), drink.begin() + k, avg) - drink.begin();
  int id2 = upper_bound(cake.begin(),cake.begin() + m, avg) - cake.begin();

  
  if ((id1 >= k) ||((avg - drink[id1 - 1]) <= (drink[id1] - avg))) id1--;
  if ((id2 >= m) ||((avg - cake[id2 - 1]) <= (cake[id2] - avg))) id2--;  
  cout << (ll)cake[id2] << " " << (ll)drink[id1] << "\n";
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test;
  int testcase = 1;
  cin >> test;
  while (test--) {
    cout << "Case #" << testcase++ << ": ";
    solve();
  }
}
