#include <bits/stdc++.h>

using namespace std;

#define newl '\n'
#define bug1(x, i) cout << #x << '[' << i << "] = " << x[i] << newl
#define bug2(x, i, j) cout << #x << '[' << i << "][" << j << "] = " << x[i][j] << newl
#define bug3(x, i, j, k) cout << #x << '[' << i << "][" << j << "][" << k << "] = " << x[i][j][k] << newl

#define mp make_pair
#define pb push_back
#define sz(v) int((v).size())

template <class T1, class T2> ostream &operator<<(ostream &os, pair<T1, T2> const &v) {
    return os << '(' << v.ff << ", " << v.ss << ')';
}

int Rand(int l, int r) {
    static mt19937 rg(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<>(l, r)(rg);
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
#define maxn 100003



int main() {
    #ifdef KITTENS
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    //ios_base::sync_with_stdio(0); cin.tie(0);



    cerr << 0.001 * clock() << newl; return 0;
}