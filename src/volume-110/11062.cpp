// author : the__martian
// 11062
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

string Tolower(string &s) {
  string res = "";
  for (char &c : s) {
    if (c >= 'A' && c <= 'Z')
      res += (c - 'A' + 'a');
    else if ( c == '-' || (c >= 'a' && c <= 'z'))
      res += c;    
  }
  return res;
}

bool Valid(char &c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '-';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  set<string> data;
  string last, cur, s;
  while (getline(cin, s)) {
    if (s == "")
      continue;
    int l = sz(s);
    for (int i = 0; i < l; i++) {
      if (Valid(s[i])) {
        cur += s[i];
      } else if (cur != "") {
        last += cur;
        data.insert(Tolower(last));
        last = cur = "";
      }
    }
    if (cur == "")
      continue;
    if (cur[sz(cur) - 1] != '-') {
      last += cur;
      data.insert(Tolower(last));
      last = cur = "";
    } else {
      last += cur.substr(0, sz(cur) - 1);
      cur = "";
    }
  }
  for (auto it = data.begin(); it != data.end(); it++) {
    cout << *it << "\n";
  }
}
