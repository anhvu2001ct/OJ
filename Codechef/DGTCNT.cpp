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

int q;
ll L, R;
int a[10], cpf[10];
ll fac[20];	

vector<int> tovec(ll n) {
	vector<int> res;
	while (n) res.pb(n%10), n /= 10;
	reverse(res.begin(), res.end());
	return res;
}

ll C(int k, int n) {
	if (k < 0 || k > n) return 0;
	return fac[n] / fac[k] / fac[n-k];
}

ll power(int a, int n) {
	ll res = 1;
	while (n--) res *= a;
	return res;
}

ll calc(int mask, int space) {
	ll res = 1;
	fto (bit, 0, 9) if (onb(mask, bit)) {
		int need = a[bit] - cpf[bit];
		res *= C(need, space);
		space -= need;
	}
	if (space > 0) res *= power(10 - bc(mask), space);
	return res;
}

ll solve(ll n) {
	vector<int> v = tovec(n);
	ll ans = 0;
	fto1 (mask, 0, 1) {
		ll res = 0;
		fto (i, 0, 9) cpf[i] = 0;
		fto (pf, 0, sz(v)) {
			if (pf) ++cpf[v[pf - 1]];
			if (pf == sz(v)) {
				++res;
				fto (bit, 0, 9) if (onb(mask, bit)) {
					if (cpf[bit] == a[bit]) continue;
					--res;
					break;
				}
				continue;
			}
			fto1 (next, 0, v[pf]) {
				if (!pf && !next) {
					fto1 (_space, 1, sz(v)) {
						fto (i, 1, 9) {
							++cpf[i];
							res += calc(mask, _space - 1);
							--cpf[i];
						}
					}
				} else {
					++cpf[next];
					res += calc(mask, sz(v) - pf - 1);
					--cpf[next];
				}
			}
		}
		if (bc(mask)%2) ans += res;
		else ans -= res;
	}
	
	return ans;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fac[0] = 1;
	fto (i, 1, 19) fac[i] = fac[i-1] * i;

	cin >> q;
	while (q--) {
		cin >> L >> R;
		fto (i, 0, 9) cin >> a[i];
		cout << R - L + 1 - (solve(R) - (L == 1 ? 0 : solve(L-1))) << endl;
	}

	cout << solve(R) << endl;

	#ifdef KITTENS
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}