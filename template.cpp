#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define fto(i, s, e) for(int i = s; i <= e; ++i)
#define fto1(i, s, e) for(int i = s; i < e; ++i)
#define fdto(i, s, e) for(int i = s; i >= e; --i)
#define fit(var, it) for(auto it = var.begin(); it != var.end(); ++it)
#define frit(var, it) for(auto it = var.rbegin(); it != var.rend(); ++it)

#define newl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

#define pc __builtin_popcountll

#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define sz(v) int((v).size())

template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.ff << ", " << v.ss << ')';
}

template<typename T, typename Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 103



int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0); cin.tie(nullptr);

	

	cerr << 0.001*clock() << newl; return 0;
}