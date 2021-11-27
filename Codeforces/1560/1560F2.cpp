#ifdef _LOCAL
	#include "local_include.hpp"
#else
	#include <bits/stdc++.h>
	using namespace std;
#endif
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define fto(i, s, e) for (int i = (s); i <= (e); ++i)
#define fto1(i, s, e) for (int i = (s); i < (e); ++i)
#define fdto(i, s, e) for (int i = (s); i >= (e); --i)
#define fit(it, a) for (auto it = (a).begin(); it != (a).end(); ++it)

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define bc __builtin_popcountll
#define endl '\n'
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define buga(a, s, e) fto(__i, s, e) cout << a[__i] << " \n"[__i == e];
#define bugar(a, s, e) cout << '{'; if (e < s) cout << '}'; else fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

template<typename T>
void bug(T const &var) { cout << var << endl; }

template<typename T, typename... Args>
void bug(T const &var, Args const &... args) {
	cout << var << ' ';
	bug(args...);
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 2e5+5;

string s;
int k;

#define multi_test 1
void _main() {
	cin >> s >> k;
	map<int, int> cnt;

	fto1 (i, 0, sz(s)) {
		if (cnt.count(s[i])) {
			++cnt[s[i]];
			continue;
		}
		if (k) ++cnt[s[i]], --k;
		else {
			auto next = cnt.upper_bound(s[i]);
			if (next != cnt.end()) {
				s[i] = next->first;
				fto1 (j, i+1, sz(s)) s[j] = cnt.begin()->first;
			} else {
				fdto (j, i-1, 0) {
					auto next = cnt.upper_bound(s[j]);
					if (--cnt[s[j]] == 0) {
						cnt.erase(s[j]);
						++cnt[++s[j]];
						int val = cnt.begin()->first;
						if (next != cnt.end() && s[j] == next->first) val = 0 + '0';
						fto1 (k, j+1, sz(s)) s[k] = val;
						break;
					}
					if (next != cnt.end()) {
						s[j] = next->first;
						fto1 (k, j+1, sz(s)) s[k] = cnt.begin()->first;
						break;
					}
				}
			}
			break;
		}
	}
	bug(s);
}

int main() {
	#ifdef _LOCAL
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int t = 1; if (multi_test) cin >> t;
	while (t--) _main();

	#ifdef _LOCAL
		cerr << 0.001*clock() << endl;
	#endif
	return 0;
}