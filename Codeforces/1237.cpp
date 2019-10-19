#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define forit(it, l, r) for(auto it = (l); it != (r); ++it)
#define fit(it, var) forit(it, (var).begin(), (var).end())
#define frit(it, var) forit(it, (var).rbegin(), (var).rend())

#define endl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << endl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << endl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << endl

#define bc __builtin_popcountll
#define onb(x, bit) ((x & (1 << bit)) != 0)
#define gcd __gcd
#define y1 ansdj

#define ll long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.x << ", " << v.y << ')';
}

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 200003

int n;
int a[maxn], b[maxn], pos[maxn], g[maxn], ans[maxn];
int f[4*maxn];
set<ii> s;

void buildST(int id, int l, int r) {
	if (l == r) {
		f[id] = b[l];
		return;
	}
	int mid = (l+r)/2;
	buildST(2*id, l, mid);
	buildST(2*id+1, mid+1, r);
	f[id] = min(f[2*id], f[2*id+1]);
}

void update(int id, int l, int r, int pos) {
	if (pos > r || pos < l) return;
	if (l == r) {
		f[id] = oo;
		return;
	}
	int mid = (l+r)/2;
	update(2*id, l, mid, pos);
	update(2*id+1, mid+1, r, pos);
	f[id] = min(f[2*id], f[2*id+1]);
}

int get(int id, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return oo;
	if (ql <= l && qr >= r) return f[id];
	int mid = (l+r)/2;
	return min(get(2*id, l, mid, ql, qr), get(2*id+1, mid+1, r, ql, qr));
}

int dist(int l, int r) {
	if (l < r) return r-l;
	return n-l+r;
}

bool comp(int a, int b, int c) {
	if (b > a && c < a) return 1;
	if (b < a && c > a) return 0;
	return b < c;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	fto (i, 1, n) {
		cin >> a[i];
		s.insert({a[i], i});
		g[i] = oo;
	}

	int cnt = 0;
	fit (it, s) {
		++cnt;
		pos[it->y] = cnt;
		b[cnt] = it->y;
	}

	buildST(1, 1, n);

	fto (i, 1, n) {
		auto p = s.lower_bound({a[i]/2 + a[i]%2, -1});
		if (p != s.begin()) {
			--p;
			g[i] = get(1, 1, n, 1, pos[p->y]);
		}
	}

	fto (i, 1, n) {
		auto p = s.lower_bound({a[i]/2 + a[i]%2, -1});
		if (p != s.begin()) {
			--p;
			int tmp = get(1, 1, n, 1, pos[p->y]);
			if (tmp != oo) g[i] = tmp;
		}
		update(1, 1, n, pos[i]);
	}
	
	set<int> sp;
	frit (it, s) {
		if (it == s.rbegin()) {
			ans[it->y] = (g[it->y] == oo) ? -1 : dist(it->y, g[it->y]);
		} else {
			auto tmp = sp.upper_bound(it->y);
			if (tmp == sp.end()) tmp = sp.begin();
			if (g[it->y] == oo) ans[it->y] = (ans[*tmp] == -1) ? -1 : (dist(it->y, *tmp) + ans[*tmp]);
			else {
				if (comp(it->y, *tmp, g[it->y])) ans[it->y] = (ans[*tmp] == -1) ? -1 : (dist(it->y, *tmp) + ans[*tmp]);
				else ans[it->y] = dist(it->y, g[it->y]);
			}
		}
		sp.insert(it->y);
	}

	fto (i, 1, n) cout << ans[i] << ' ';

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}