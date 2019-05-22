#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << '\n'
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << '\n'
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << '\n'

#define ll long long
#define mp make_pair
#define pb push_back
#define sz(v) int((v).size())

template<class T1, class T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
	return os << '(' << v.first << ", " << v.second << ')';
}

template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 1003



int main() {
	#ifdef KITTENS
		freopen("main.inp", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
	//ios_base::sync_with_stdio(0); cin.tie(0);
	


	cerr << 0.001*clock() << '\n'; return 0;
}