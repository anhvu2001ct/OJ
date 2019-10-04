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
#define onb(x, bit) (x & (1 << bit))
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

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL

int n, k;
int cnt[200003];
string s, rgb = "RGB";
string pt[3];

int calc(string &str) {
	int res = oo;
	fto (i, 1, n) cnt[i] = cnt[i-1] + (s[i] != str[i-1]);
	fto (i, k, n) {
		res = min(res, cnt[i] - cnt[i-k]);
	}
	return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int q; cin >> q;
	while (q--) {
		cin >> n >> k >> s;
		s = " " + s;
		fto (i, 0, 2) pt[i].clear();
		fto1 (i, 0, n) {
			pt[0] += rgb[i%3];
			pt[1] += rgb[(i+1)%3];
			pt[2] += rgb[(i+2)%3];
		}
		int ans = oo;
		fto (i, 0, 2) ans = min(ans, calc(pt[i]));
		cout << ans << endl;
	}

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}
