// author: the__martian
// 429
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

vector<vi> g(205);
int n;
vector<bool> vis(205);
vector<int> dis(205);

int bfs(int s, int des){
  if (s == des) return 0;
  vis.assign(n, false);
  dis.assign(n, 0);
  dis[s] = 0;
  queue<int> q;
  q.push(s);
  while (q.size()) {
    int u = q.front(); q.pop();
    for (auto v : g[u]){
      if (v == des) return dis[u] + 1;
      if (vis[v] == false) {
        dis[v] = dis[u] + 1;
        q.push(v);
        vis[v] = true;
      }
    }
  }
  return -1;
}


bool valid(string a, string b){
  if (sz(a) != sz(b))
    return false;
  int d = 0;
  for (int i = 0;i < sz(a); i++)
    d += a[i] != b[i];
  return d == 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  unordered_map<string, int> mp;
  vector<string> word(205);
  string s;
  int test; getline(cin, s);test = stoi(s);
  getline(cin, s);
  while (test--){
    n = 0;
    while (getline(cin, s), s != "*"){
      word[n] = s;
      mp[s] = n++;
    }
    rep(i,0,n){
      rep(j,i + 1,n){
        if (valid(word[i], word[j])){
          g[i].push_back(j);
          g[j].push_back(i);
        }
      }
    }
    while(getline(cin, s)) {
      if ( s == "")
        break;
      stringstream ss(s);
      string a, b; ss >> a >> b;
      cout << s << " ";
      cout << bfs(mp[a], mp[b]) << "\n";
    }
    if (test)
      cout << "\n";
    mp.clear();
    for ( int i = 0; i < 205; i++)
      g[i].clear();
  }
}