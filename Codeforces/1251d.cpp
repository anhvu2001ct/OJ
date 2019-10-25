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
#define oo 1000000000
#define OO 1000000000000000003LL
#define maxn 200003

int t, n;
ii a[maxn];
bool visit[maxn];
ll s;

bool check(int val) {
	vector<int> v, l, r;
	fto (i, 1, n) {
		if (a[i].x <= val) v.pb(i);
		visit[i] = 0;
	}
	ll cur = 0;
	fit (it, v) {
		if (a[*it].y < val) l.pb(a[*it].x), visit[*it] = 1;
	}
	fit (it, v) {
		if (sz(l) < n/2 && a[*it].y >= val) l.pb(a[*it].x), visit[*it] = 1;
	}
	fto (i, 1, n) {
		if (visit[i]) continue;
		if (a[i].x <= val) r.pb(val);
		else r.pb(a[i].x);
	}
	fit (it, l) cur += *it;
	fit (it, r) cur += *it;
	return sz(l) == n/2 && sz(r) == 1+n/2 && r.front() == val && cur <= s; 
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> s;
		int left, right = 0;
		fto (i, 1, n) {
			cin >> a[i].x >> a[i].y;
			right = max(right, a[i].y);
		}
		sort(a+1, a+1+n);
		left = a[n/2+1].x;
		int ans = left;
		while (left <= right) {
			int mid = (left+right)/2;
			if (check(mid)) ans = mid, left = mid+1;
			else right = mid-1;
		}
		bug(ans);
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
