
#include <bits/stdc++.h>

using namespace std;

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

int n, ans;
vector<int> b;
int w[maxn], f[maxn];
pair<ii, int> a[maxn];

bool cmp(pair<ii, int> &l, pair<ii, int> &r) {
	return l.y < r.y;
}

void update(int idx, int val) {
	for (; idx <= sz(b); idx += idx & -idx) {
		f[idx] = max(f[idx], val);
	}
}

int get(int idx) {
	int res = 0;
	for (; idx; idx -= idx & -idx) {
		res = max(res, f[idx]);
	}
	return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;

	fto (i, 1, n) {
		cin >> a[i].y >> w[i];
		b.pb(a[i].y);
		b.pb(a[i].y-w[i]);
		b.pb(a[i].y+w[i]);
	}

	sort(b.begin(), b.end());

	b.erase(unique(b.begin(), b.end()), b.end());

	fto (i, 1, n) {
		a[i].x.x = lower_bound(b.begin(), b.end(), a[i].y - w[i]) - b.begin()+1;
		a[i].x.y = lower_bound(b.begin(), b.end(), a[i].y + w[i]) - b.begin()+1;
		a[i].y = lower_bound(b.begin(), b.end(), a[i].y) - b.begin()+1;
	}

	sort(a+1, a+1+n, cmp);

	fto (i, 1, n) {
		int res = get(a[i].x.x)+1;
		ans = max(ans, res);
		update(a[i].x.y, res);
	}

	cout << ans << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}