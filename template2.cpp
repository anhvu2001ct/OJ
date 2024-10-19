#include <bits/stdc++.h>

#ifdef _LOCAL
    #include "local.hpp"
#endif

using namespace std;

#define sz(x) (x).size()
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define ll long long

int tests = 1;
int const oo = (int)1e9 + 7;
int const maxn = (int)2e5 + 3;

void before_all() {

}

void _main(int tc) {
    
}

int main() {
    #ifdef _LOCAL
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> tests;
    before_all();
    for (int i = 1; i <= tests; ++i) _main(i);

    #ifdef _LOCAL
        cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s has elapsed" << endl;
    #endif
    return 0;
}
