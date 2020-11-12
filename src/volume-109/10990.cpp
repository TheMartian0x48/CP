// @author: the__martian
// 10990

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



// Generating phi [1 ... r]
vector<long long> phi;
void PhiRange(long long n = 100) {
  phi.resize(n + 1);
  for (int i = 0; i <= n; i++) phi[i] = i;
  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) { // when i is prime
      for (int j = i; j <= n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
  }
}

int depth(int n) {
  int c = 0;
  while (n != 1) {
    n = phi[n];
    c++;
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int N = 2e6+1;
  PhiRange(N);
  vi v(N);
  for (int i = 1; i < N; i++) {
    v[i] = depth(i);
    v[i] += v[i - 1];
  }

  int t; cin >> t;
  while (t-- ) {
    int a, b; cin >> a >> b;
    cout << v[b] - v[a - 1] << "\n";
  }
}
