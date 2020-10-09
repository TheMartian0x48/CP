// author: the__martian
// 1197
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

struct DSU{
  vi par, size;
  DSU(int n){
    par.resize(n);
    size.resize(n);
    rep(i,0,n){
      par[i] = i;
      size[i] = 1;
    }
  }
  int find(int x){
    if (x == par[x])
      return x;
    return par[x] = find(par[x]);
  }
  void merge(int x, int y){
    int a = find(x);
    int b = find(y);
    if (a == b) return;
    if (size[a] > size[b]){
      size[a] += size[b];
      par[b] = a;
    } else {
      size[b] += size[a];
      par[a] = b;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, m;
  while (cin >> n >> m){
    if (n == 0 && m == 0)
      break;
    DSU st(n);
    rep(i,0,m){
      int k, a; cin >> k;
      if (k) {
        cin >> a;
      }
      rep(z,1,k){
        int b; cin >> b;
        st.merge(a, b);
      }
    }
    int res = st.size[st.find(0)];
    cout << res << "\n";
  }
}