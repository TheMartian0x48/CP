// @author: the__martian
// 10394
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

vector<ll> prime;
vector<pair<ll,ll>> twin;

void Prime() {
  const ll N = 2e7;
  bitset<N> bt;
  bt.set();
  bt.reset(0), bt.reset(1);
  for (ll i = 2; i < N; i++) {
    if (bt[i]) {
      for (ll j = i * i; j < N; j += i) {
        bt.reset(j);
      }
    }
    prime.push_back(i);
  }
  twin.push_back({3,5});
  ll i;
  for (i = 1; 6 * i + 1 <= N; i++) {
    if (bt[6 * i - 1] && bt[6 * i + 1]) {
      twin.push_back({6 * i - 1, 6 * i + 1});
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  Prime();
  ll n;
  while (cin >> n) {
    n--;
    cout << "(" << twin[n].first << ", " << twin[n].second << ")\n";
  }
}