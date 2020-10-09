// author: the__martian
// 10475
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

string ToUpper(string &s){
  string res;
  for (auto c : s) {
    if (c >= 'a')
      res += c - 'a' + 'A';
    else 
      res += c;
  }
  return res;
}

bool cmp(const string& a, const string& b){
  return sz(a) > sz(b) || (sz(a) == sz(b) && a < b);
}

vector<string> topic(20), res;
unordered_map<string, set<string>> mp;
int t, p, s; 
vi idx(5);

void solve(string str = "", int i = 0, int in = 0) {
  if (in == s) {
    cout << str << "\n";
    return;
  }
  if (i >= t) {
    return;
  }

  for (int j = i; j < t; j++) {
    bool valid = true;
    for (int k = 0; k < in; k++) {
      if (mp[topic[idx[k]]].find(topic[j]) != mp[topic[idx[k]]].end()){
        valid = false;
        break;
      }
    }
    if (valid) {
      idx[in] = j;
      if (i == 0)
        solve(topic[j], j + 1, in + 1);
      else 
        solve(str + " " + topic[j], j + 1, in + 1);
    }
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int tt; cin >> tt; tt++;
  
  rep(test, 1, tt) {
    cout << "Set " << test << ":\n";
    cin >> t >> p >> s;
    string str, tmp;

    rep(i,0,t) {
      cin >> str;
      topic[i] = ToUpper(str);
    }
    sort(topic.begin(), topic.begin() + t, cmp);
    rep(i,0,p){
      cin >> str >> tmp;
      mp[ToUpper(str)].insert(ToUpper(tmp));
      mp[ToUpper(tmp)].insert(ToUpper(str));
    }
    solve();
    cout << "\n";
    mp.clear();
  }  
}