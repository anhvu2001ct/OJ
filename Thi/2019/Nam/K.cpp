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
#define maxn 1000003

int n;
int a[maxn], Rmin[maxn], Rmax[maxn], Lmin[maxn], Lmax[maxn], bit[maxn];
deque<int> d1, d2;

void push1(int idx, int *l, int *r) {
	while (!d1.empty() && a[d1.back()] > a[idx]) {
		r[d1.back()] = idx - 1;
		d1.pop_back();
	}
	l[idx] = d1.empty() ? 1 : (d1.back()+1);
	d1.pb(idx);
}

void push2(int idx, int *l, int *r) {
	while (!d2.empty() && a[d2.back()] < a[idx]) {
		r[d2.back()] = idx - 1;
		d2.pop_back();
	}
	l[idx] = d2.empty() ? 1 : (d2.back()+1);
	d2.pb(idx);
}

void update(int idx, int val) {
	for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}

int get(int idx) {
	int res = 0;
	for (; idx; idx -= idx & -idx) res += bit[idx];
	return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	scanf("%d", &n);
	fto (i, 1, n) {
		scanf("%d", &a[i]);
		push1(i, Lmin, Rmin);
		push2(i, Lmax, Rmax);
	}

	while (!d1.empty()) Rmin[d1.back()] = n, d1.pop_back();
	while (!d2.empty()) Rmax[d2.back()] = n, d2.pop_back();

	ll ans = 0;
	vector<ii> v;
	fto (i, 1, n) {
		v.pb({i, Rmin[i]});
		update(Lmax[i], 1);
		update(i+1, -1);
		while (!v.empty() && v.back().y == i) {
			ans += get(v.back().x);
			ans %= oo;
			v.pop_back();
		}
	}

	fto (i, 1, n) bit[i] = 0;
	fto (i, 1, n) {
		v.pb({i, Rmax[i]});
		update(Lmin[i], 1);
		update(i+1, -1);
		while (!v.empty() && v.back().y == i) {
			ans += get(v.back().x);
			ans %= oo;
			v.pop_back();
		}
	}

	ans = (ans - n + oo) % oo;
	bug(ans);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
