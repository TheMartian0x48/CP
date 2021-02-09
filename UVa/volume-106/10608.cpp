// author : the__martian
// 10608
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

struct DSU {
  vector<int> s, p;
  int size;
  DSU() {}
  void Reset(int n) {
    size = n + 1;
    s.resize(n + 1);
    p.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      s[i] = 1, p[i] = i;
    }
  }
  int result() {
    return *max_element(all(s));
  }

  int find(int x) {
    if (p[x] == x)
      return x;
    return p[x] = find(p[x]);
  }

  void merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b)
      return;
    if (s[a] > s[b])
      swap(a, b);
    s[b] += s[a];
    p[a] = b;
  }
};  

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int test; cin >> test;
  DSU st;
  while (test-- ) {
    int n, m;
    cin >> n >> m;
    int a, b;
    st.Reset(n);
    while (m--) {
      cin >> a >> b;
      st.merge(a, b);
    }
    cout << st.result() << "\n";
  }
}

