#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fto(i, s, e) for (int i = s; i <= e; ++i)
#define fto1(i, s, e) for (int i = s; i < e; ++i)
#define fdto(i, s, e) for (int i = s; i >= e; --i)
#define fit(var, it) for (auto it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for (auto it = var.rbegin(); it != var.rend(); ++it)

#define newl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

#define pc __builtin_popcountll

#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}

template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 10003

int n;
int f[maxn];
vector<ii> v[maxn], h[maxn];
vector<int> cnt[maxn];

void upd(int idx, int val) {
	for (; idx <= 10001; idx += idx & -idx) {
		f[idx] += val;
	}
}

int get(int idx) {
	int res = 0;
	for (; idx; idx -= idx & -idx) {
		res += f[idx];
	}
	return res;
}

int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
    //ios_base::sync_with_stdio(0); cin.tie(nullptr);
	
	scanf("%d", &n);

	fto (i, 1, n) {
		int a1, b1, a2, b2;
		scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
		a1 += 5001; a2 += 5001; b1 += 5001; b2 += 5001;
		if (a1 > a2) swap(a1, a2);
		if (b1 > b2) swap(b1, b2);
		if (a1 == a2) {
			v[a1].pb({b1, b2});
		} else {
			h[b1].pb({a1, a2});
		}
	}

	ll ans = 0;

	fto (y, 1, 10001) {
		fto1 (i, 0, sz(h[y])) {
			fto (j, 1, 10001) {
				cnt[j].clear();
				f[j] = 0;
			}

			ii ngang1 = h[y][i];
			fto (x, ngang1.ff, ngang1.ss) {
				fto1 (j, 0, sz(v[x])) {
					ii doc = v[x][j];
					if (doc.ff <= y && doc.ss > y) {
						cnt[doc.ss].pb(x);
						upd(x, 1);
					}
				}
			}

			fto (_y, y+1, 10001) {
				fto1 (j, 0, sz(h[_y])) {
					ii ngang2 = h[_y][j];
					int l = max(ngang1.ff, ngang2.ff);
					int r = min(ngang1.ss, ngang2.ss);
					if (l > r) continue;
					int cur = get(r) - get(l-1);
					ans += (ll)cur*(cur-1)/2;
				}
				for (auto x : cnt[_y]) upd(x, -1);
			}
		}
	}

	cout << ans << newl;

    cerr << 0.001*clock() << newl; return 0;
}