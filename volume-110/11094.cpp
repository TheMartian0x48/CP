
// author: the__martian
// 11094
#include <bits/stdc++.h>
using namespace std;

vector<string> v(40);
int n, m;

int dfs(int r, int c, char ch){
	if (r < 0 || r >= m || v[r][c] != ch) return 0;
	v[r][c] = '\n';
	int t =  1 + dfs(r - 1, c, ch) + dfs(r + 1, c, ch) 
		+ dfs(r, c - 1 < 0 ? n - 1 : c - 1, ch) + dfs(r, (c + 1) % n, ch);
	return t;
}


int main() {

	
	while(cin >> m >> n){
		for(int i = 0; i < m; i++){
			cin >> v[i];
		}
		int x, y; cin >> x >> y;
		char land = v[x][y];
		dfs(x, y, land);
		int t = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] == land){
					t = max(t, dfs(i, j, land));
				}
			}
		}
		cout << t  << "\n";
	}
}