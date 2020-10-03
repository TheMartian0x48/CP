
// author: the__martian
// 872
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


vector<vi> g(30);
vector<int> in(30);
unordered_map<char, int> idx;
unordered_map<int, char> name;
int n;
vector<bool> vis(30);
bool sol;
vi order(30);

void dfs(int u, int id = 0){
  order[id] = u;
  if (id == n - 1){
    for (int i = 0; i < n; i++){
      cout << name[order[i]];
      if (i != n - 1)
        cout << " ";
    }
    sol = true;
    cout << "\n";
    return;
  }
  vis[u] = true;
  for (auto v : g[u]){
    in[v]--;
  }
  for (int i = 0; i < n; i++) {
    if (vis[i] == false && in[i] == 0){
      dfs(i, id + 1);
    }
  }
  for (auto v : g[u]){
    in[v]++;
  }
  vis[u] = false;
}


void solve(){
  rep(i,0,n)
    vis[i] = false;

  sol = false;
  for (int i = 0; i < n; i++){
    if (in[i] == 0){
      dfs(i);
    }
  }

}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  string s, str, t; getline(cin, t);
  int tt = stoi(t);
  while (tt--) {
    getline(cin, s);
    getline(cin, s);
    getline(cin, str);
    stringstream ss(s), sm(str);
    s = "";
    while (ss >> t){
      s+= t[0];
    }
    n = sz(s);
    sort(all(s));
    rep(i,0,n){
      idx[s[i]] = i;
      name[i] = s[i];
    }

    while (sm >> t){
      in[idx[t[2]]]++;
      g[idx[t[0]]].push_back(idx[t[2]]);
    }

    solve();
    if (!sol)
        cout << "NO\n";
    if (tt)
      cout << "\n";
    rep(i,0,30)
      vis[i] = false, in[i] = 0, g[i].clear();
    name.clear();
    idx.clear();
  }
}
