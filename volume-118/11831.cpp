// author: the__martian
// 11831
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

vector<string> v(105);
int r, c, d, n, m, s, res;
vi dr{-1, 0, 1, 0}, dc{0, 1, 0, -1};

void move(char ch) {
  if (ch == 'D') {
    d = (d + 1) % 4;
  } else if (ch == 'E') {
    d = d - 1;
    if (d == -1)
      d = 3;
  } else {
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (nr < 0 || nc < 0 || nr >= n || nc >= m|| v[nr][nc] == '#')
      return;
    res += v[nr][nc] == '*';
    if (v[nr][nc] == '*')
      v[nr][nc] = '.';
    r = nr;
    c = nc;
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while (cin >> n >> m >> s) {
    if (n == 0 && m == 0 && s == 0)
      break;
    res = 0;
    rep(i,0,n) {
      cin >> v[i];
      rep(j,0,m){
        if (v[i][j] == 'N'){
          d = 0;
          r = i, c = j;
        } else if (v[i][j] == 'L'){
          d = 1;
          r = i, c = j;
        } else if (v[i][j] == 'S'){
          d = 2;
          r = i, c = j;
        } else if (v[i][j] == 'O'){
          d = 3;
          r = i, c = j;
        }
      }
    }
    string str; cin >> str;
    for (auto ch : str){
      move(ch);
    }
    cout << res << "\n";
  }
}