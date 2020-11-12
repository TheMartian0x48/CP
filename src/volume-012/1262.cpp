// author : the__martian
// 1262 
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

vector<string> v1(6), v2(6), res(8000);
int n;
unordered_set<string> st;

void dfs(string s = "", int idx = 0) {

  if (idx == 5) {
    st.insert(s);
    return;
  }

  for (int i = 0; i < (int)v1[idx].size(); i++) {
    for (int j = 0; j < (int)v2[idx].size(); j++) {
      if (v1[idx][i] ==  v2[idx][j]) {
        dfs(s + v1[idx][i], idx + 1);
      }
    }
  }
}

void read(int id) {
  vector<string> v(6);
  for (int i = 0; i < 6; i++)
      cin >> v[i];
  for (int i = 0; i < 5; i++) {
    vector<bool> tmp(26, false);
    for (int j = 0; j < 6; j++) {
      tmp[v[j][i] - 'A']  = true;
    }
    string s;
    for (int j = 0; j < 26; j++) {
      if (tmp[j]) {
        s += 'A' + j;
      }
    }
    if (id == 1)
      v1[i] = s;
    else 
      v2[i] = s;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  
  int test; cin >> test;
  while (test--) {
    int k; cin >> k;
    n = 0;
    
    read(1);
    read(2);

    dfs();
    for (auto it = st.begin(); it != st.end(); it++) {
      res[n++] = *it;
    }
    st.clear();
    sort(res.begin(), res.begin() + n);
    if (k > n)
      cout << "NO\n";
    else  {
      cout << res[k - 1] << "\n";
    }
  }
}
