#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<typename T, typename Cmp = less<T>>
using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

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
#define maxn 1000003

int n;
int a[maxn], f[maxn], g[maxn];
bool prime[maxn];
oss<ii> s;

void sieve(int n) {
	fto (i, 2, n) prime[i] = 1;
	for (int i = 2; (ll)i*i <= n; ++i) {
		if (prime[i]) for (int j = i*i; j <= n; j += i) prime[j] = 0;
	}
}


int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	sieve(1e6);

	fto (i, 1, n) {
		cin >> a[i];
		f[i] = f[i-1] + prime[a[i]];
        g[i] = g[i-1] + !prime[a[i]];
        //bug(f[i], g[i]);
	}

	int cnt = 0;
    ll ans = 0;

	fto (i, 1, n) {
        s.insert(ii(f[i-1] - g[i-1], ++cnt));
        int v = s.order_of_key(ii(f[i]-g[i]+1, 0));
        ans += v;
	}

	cout << ans << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}