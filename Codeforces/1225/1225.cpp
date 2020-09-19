#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fto(i, s, e) for(int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for(int i = (s); i < (e); ++i)
#define fdto(i, s, e) for(int i = (s); i >= (e); --i)
#define fit(it, var) for(auto it = (var).begin(); it != (var).end(); ++it)
#define frit(it, var) for(auto it = (var).rbegin(); it != (var).rend(); ++it)

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

template<class T> ostream& operator<< (ostream &os, vector<T> const &v) {
	os << '['; for (int i = 0; i < sz(v); ++i) { os << v[i]; if (i < sz(v)-1) os << ' '; }
	return os << ']';
}

template<class T> void bug(T const &v) { cout << v << endl; }
template<class T, class... Args> void bug(T const &v, Args const&... args) { cout << v << ' '; bug(args...); }

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 1e5+3;

int n, k;
int a[maxn], cnt[maxn];
ll ans;
vector<ii> prime;

ll power(ll a, int n) {
	ll res = 1;
	while (n) {
		if (n%2) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

void calc(int idx, ll &cur, ll &N) {
	if (cur > 1e5) return;
	if (idx == sz(prime)) {
		if (cur == N/cur) ans += (ll)cnt[cur]*(cnt[cur]-1)/2;
		else if (cur < N/cur && N/cur <= 1e5) ans += (ll)cnt[cur] * cnt[N/cur];
		return;
	}
	ll tmp = cur;
	fto (i, 0, prime[idx].y) {
		if (i) cur *= prime[idx].x;
		calc(idx+1, cur, N);
	}
	cur = tmp;
}

vector<int> p;
bool isP[maxn];

void sieve(int n) {
	for (int i = 2; (ll)i*i <= n; ++i) {
		if (!isP[i]) for (int j = i*i; j <= n; j += i) isP[j] = 1;
		if (i > 2) ++i;
	}
	fto (i, 2, n) if (!isP[i]) p.pb(i);
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	fto (i, 1, n) {
		cin >> a[i];
		++cnt[a[i]];
	}

	int lim = pow(1e10, 1.0/k);

	sieve(1e5);

	fto (i, 2, lim) {
		ll val = power(i, k), tmp = val;
		prime.clear();
		for (int j = 0, v = p[j]; j < sz(p) && (ll)v*v <= tmp; v = p[++j]) {
			if (tmp%v == 0) {
				prime.pb({v, 0});
				while (tmp%v == 0) ++prime.back().y, tmp /= v;
			}
		}
		ll cur = 1;
		calc(0, cur, val);
	}

	bug(ans + (ll)cnt[1]*(cnt[1]-1)/2);

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}