/*
 *TheMartian0x48
 */

/*
Problem: https://www.codechef.com/FEB21C/problems/FROGS
Solution: https://www.codechef.com/viewsolution/42273158
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

struct tata{
    int p, w, r;
    bool operator<(const tata & a) {
        return w < a.w;
    }
};

void solve()
{
    int n, t;
    cin >> n;
    vector<tata> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].w;
        v[i].p = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].r;
    }
    sort(all(v));
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].p > v[i - 1].p) continue;
        int d = v[i - 1].p - v[i].p;
        t = d / v[i].r;
        res += t + 1;
        v[i].p += (t + 1) * v[i].r;
    }
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // clang-format off
    int test;
    cin >> test;
    // string s; getline(cin, s); test = stoi(s);
    while (test--)
        solve();
    // clang-format on
}
