/*
 * TheMartian0x48
 */

#include <bits/stdc++.h>
using namespace std;

#define LEFT  true
#define RIGHT  false

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n; cin >> n;
  vector<vector<int>> v(500, vector<int>(500, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 500; j++)  
      v[j].assign(500, 0);
    string s; cin >> s;
    int r = 250, c = 250;
    v[r][c] = 2;

    for (auto a : s) {
      if (a == 'W') {
        for (int j = 1; j <= 2; j++)
          v[r][c - j] = 2;
        c -= 2;
      } else if (a == 'E'){
        for (int j = 1; j <= 2; j++)
          v[r][c + j] = 2;
        c += 2;
      } else if (a == 'N') {
        for (int j = 1; j <= 2; j++)
          v[r - j][c] = 2;
        r -= 2;
      } else {
        for (int j = 1; j <= 2; j++)
          v[r + j][c] = 2;
        r += 2;
      }
    }
    for (int r = 0; r < 500; r++) {
      int val = 0;
      for (int c = 0; c < 500; c++) {
        if (val == 0 && v[r][c] == 2) {
          val = 1;
          continue;
        } else if (val == 1 && v[r][c] == 2) {
          val = 0;
          continue;
        }
        v[r][c] = val;
      }
    }
    bool left = true;
    if (s[0] == 'W' && v[249][249] == 1) { 
      left = false;
    } else if (s[0] == 'E' && v[251][251] == 1) {
      left = false;
    }else if (s[0] == 'N' && v[249][251] == 1) {
      left = false;
    } else if (s[0] == 'S' && v[251][249] == 1) {
      left = false;
    }
    if (left) {
      cout << "CCW\n";
    } else {
      cout << "CW\n";
    }

  }
}
