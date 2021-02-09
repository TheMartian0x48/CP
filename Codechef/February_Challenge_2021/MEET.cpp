/*
 *TheMartian0x48
 */

/*
Problem: https://www.codechef.com/FEB21C/problems/MEET
Solution: https://www.codechef.com/viewsolution/42263973
*/
#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
// (* math *)
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on

// ---------------- (* Extract here *)
// ----------------

int timestap(const string &str)
{
    int h = (str[0] - '0') * 10 + str[1] - '0';
    int m = (str[3] - '0') * 10 + str[4] - '0';
    if (h == 12)
        h = 0;

    if (str[str.size() - 2] == 'P')
        h += 12;
    return h * 60 + m;
}

void solve()
{
    string s, res;
    getline(cin, s);
    int meet = timestap(s);
    int n;
    getline(cin, s);
    n = stoi(s);
    rep(i, 0, n)
    {
        getline(cin, s);
        int st = timestap(s.substr(0, 8));
        int ft = timestap(s.substr(9, s.size()));
        res += '0' + (meet >= st && meet <= ft);
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // clang-format off
    int test;
//   cin >> test;
    string s; getline(cin, s);
    test = stoi(s);
    while (test--)
        solve();
    // clang-format on
}
