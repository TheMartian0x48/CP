
// author: the__martian
// 11239
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



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while(true) {
      string s;
      getline(cin, s);
      if (s == "0") break;
      unordered_map<string, unordered_set<string>> project;
      unordered_map<string, vector<string>> user;
      string pro = s;
      project[pro].insert(s);
      project[pro].erase(s);
      while (true) {
        getline(cin, s);
        if (s == "1") break;
        if (s[0] <= 'Z') {
          pro = s;
          project[pro].insert(s);
          project[pro].erase(s);
        } else {
          project[pro].insert(s);
          user[s].push_back(pro);
        }
      }
      for (auto it = user.begin(); it != user.end(); it++){
        auto v = it->second;
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        if (v.size() > 1) {
          for (auto a : v){
            project[a].erase(it->first);
          }
        }
      }
      vector<pair<int, string>> v;
      for (auto it = project.begin(); it != project.end(); it++){
        v.push_back({it->second.size(), it->first});
      }
      auto cust = [](pair<int, string> &a, const pair<int, string> &b){
        return a.first > b.first || (a.first == b.first && a.second < b.second);
      };
      sort(all(v), cust);
      for (auto p : v) {
        cout << p.second << " " << p.first << "\n";
      }
  }
}
