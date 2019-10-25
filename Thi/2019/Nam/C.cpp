#include <bits/stdc++.h>

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
#define OO 1000000000000000003LL
#define maxn 100003

int n, m;
vector<int> a[maxn];
bool visited[maxn];
ii z1[maxn], z2[maxn];

void dfs(int u, ii *z) {
	visited[u] = 1;
	fit (it, a[u]) {
		int v = *it;
		if (!visited[v]) dfs(v, z);
		z[u].x = max(z[u].x, z[v].x ^ 1);
	}

	fit (it, a[u]) {
		int v = *it;
		if (z[u].x) {
			if (z[u].x == z[v].x^1) z[u].y = min((z[u].y == 0 ? oo : z[u].y), z[v].y + 1);
		} else {
			if (z[u].x == z[v].x^1) z[u].y = max(z[u].y, z[v].y + 1);
		}
	}
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int u, v;
	fto (i, 1, m) {
		cin >> u >> v;
		a[u].pb(v);
	}
	
	fto (i, 1, n) visited[i] = 0;
	fto (i, 1, n) {
		if (!visited[i]) dfs(i, z1);
	}

	fto (i, 1, n) bug1(z1, i);

	fto (i, 1, n) a[u].clear();
	cin >> n >> m;

	fto (i, 1, m) {
		cin >> u >> v;
		a[u].pb(v);
	}
	
	fto (i, 1, n) visited[i] = 0;
	fto (i, 1, n) {
		if (!visited[i]) dfs(i, z2);
	}

	int q; cin >> q;
	while (q--) {
		cin >> u >> v;
		if (z1[u].x && z2[v].x) bug("first");
		else if (!z1[u].x && !z2[v].x) bug("second");
		else {
			if (z1[u].y < z2[v].y) bug(z1[u].x ? "first" : "second");
			else bug(z2[v].x ? "first" : "second");
		}
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}