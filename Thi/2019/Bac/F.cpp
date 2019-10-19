#include <bits/stdc++.h>
#include <ext/rope>
 
using namespace std;
 
#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(it, var) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(it, var) for(auto it = (var).rbegin(); it != (var).rend(); ++it)
 
#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl
 
#define bc __builtin_popcountll
#define onb(x, bit) (((x >> bit) & 1) != 0)
#define y1 ansdj
 
#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
 
template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}
 
template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }
 
double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003
#define maxn 3003

int n;
ll d[1005][1005];
vector<int> ke[1005];

void solve(int s) {
	ll f[1000];
	fto (i, 1, n) f[i] = oo;
	f[s] = 0;
	//cout << s << endl;
	priority_queue<ii, vector<ii>, greater<ii>> q;
	q.push({0, s});
	while (!q.empty()) {
		int u = q.top().y;
		int k = q.top().x;
		q.pop();
		if (k <= f[u]) {
			fit (it, ke[u]) {
				int v = *it;
				//cout << v << " " << f[v] << endl;
				if (f[u]+1 < f[v]) {
					f[v] = f[u]+1;
					q.push({f[v], v});
				}
			}
		}
	}
	//fto (u, 1, n) cout << f[u];
	fto (u, 1, n) d[s][u] = f[u];
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	bool flag = 0;

	int m;
	cin >> n >> m;
	vector<pair<ll, ii>> e;
	fto (i, 1, m) {
		int u, v;
		ll c;
		cin >> u >> v >> c;
		ke[u].pb(v);
		ke[v].pb(u);
		e.pb({c, {u, v}});
	}
	
	//fto (u, 1, n) fto (v, 1, n) d[u][v] = oo;
	fto (i, 1, n) solve(i);

	ll ans = 0;

	fto (u, 1, n) {
		fto (v, u+1, n) {
			ll res = OO;
			fit (it, e) {
				int x = it->y.x;
				int y = it->y.y;
				ll c = it->x;
				//if (u == 3 && v == 4) bug(u, v, x, y, d[u][x], d[y][v], d[u][y], d[y][v]);
				if (d[u][x] != oo && d[v][y] != oo) res = min(res, (ll)(d[u][x]+d[v][y]+1)*c);
				if (d[u][y] != oo && d[v][x] != oo) res = min(res, (ll)(d[u][y]+1+d[x][v])*c);
			}
			//bug(u v, res);
			if (res != OO) ans += res;
			if (ans >= 1000000000) flag = 1;
			ans %= 1000000000;
		}
	}

	string s = "";
	while (ans) {
		s += (ans%10)+'0';
		ans /= 10;
	}
	reverse(all(s));

	if (flag) while (sz(s) < 9) s = '0'+s;
	cout << s << endl;

	//bug(d[1][1], d[2][4]);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}