/*
 * TheMartian0x48
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(1100, vector<int>(1100, 0));
vector<int> dr{-1, 0, 0, 1}, dc{0, -1, 1, 0};

bool valid(int x, int y) {
  if (v[y][x] == 0) return false;
  int c = 0;
  for (int i = 0; i < 4; i++) {
    if (v[y + dr[i]][x + dc[i]] == 1)
      c++;
  }
  return c == 3;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int res = 0;
  int a, b, n; cin >> n;
  
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    a += 5, b += 5;
    
    for (int j = 0; j < 4; j++) {
      if (valid(a + dc[j], b + dr[j]))
        res--;
    }
    v[b][a] = 1;
    for (int j = 0; j < 4; j++) {
      if (valid(a + dc[j], b + dr[j]))
        res++;
    }
    if (valid(a, b)) res++;
    cout << res << "\n";
  } 
}
