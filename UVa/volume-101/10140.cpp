// @author: the__martian
// 10140

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
const ll N = 1e6 + 10;
bitset<N> bs;
vector<bool> v(1000005);

void Prime() {  
  bs.set();
  bs.reset(0), bs.reset(1);
  for (ll i = 2; i < N; i++) {
    if (bs[i]) {
      prime.push_back(i);
      for (ll j = i * i; j < N; j += i) {
        bs.reset(j);
      }
    }
  }  
}

void solve(ll l, ll r) {
  ll n = r - l + 1;
  
  rep(i,0,n) v[i] = true;

  for (ll i = 0; i < (ll)prime.size() && 1LL * prime[i] * prime[i] <= r; i++) {
    ll p = prime[i];
    ll j = l / p * p;
    if (j < l)  j += p;
    for (; j <= r; j += p) {
      if (j % p == 0 ) {
        v[j - l] = false;
      }
    }
  }

  ll a = -1, b = -1, c = -1, d = -1, last;
      for(ll j = l; j < r + 1; j++) {
        ll i = j - l;
        if (v[i]) {
          if (a == -1) {
            c = a = i + l;
            last = i;
          } else if (b == -1) {
            last = b = d = i + l;
          } else {
            if (i + l - last < b - a) {
              a = last, b = i + l;
            }
            if (i + l - last > d - c) {
              c = last, d = i + l;
            }
            last = i + l;
          }
        }
      }
      if (a != -1 && b != -1)
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a, b, c, d);
      else 
        printf("There are no adjacent primes.\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  Prime();

  ll l, r;
  while (scanf("%lld %lld", &l, &r) == 2) {
    if (r <= N) {
      ll a = -1, b = -1, c = -1, d = -1, last;
      rep(i,l,r + 1) {
        if (bs[i]) {
          if (a == -1) {
            c = a = i;
            last = i;
          } else if (b == -1) {
            last = b = d = i;
          } else {
            if (i - last < b - a) {
              a = last, b = i;
            }
            if (i - last > d - c) {
              c = last, d = i;
            }
            last = i;
          }
        }
      }
      if (a != -1 && b != -1)
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a, b, c, d);
      else 
        printf("There are no adjacent primes.\n");
    } else {
      solve(l,r);
    }
  }
}