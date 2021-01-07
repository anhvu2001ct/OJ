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
#define fat(i, a) for (auto i : (a))

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>
template<class T, class Cmp = less<T>> using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define bc __builtin_popcountll
#define y1 ansdj
#define endl '\n'
#define ff first
#define ss second
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define buga(a, s, e) cout << '{'; if (e < s) cout << '}'; else fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

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
int const maxn = 5e5+3;

int n;
ll a[maxn];
int cnt[100];

#define multi_test 1
void _main() {
    cin >> n;
    fto (i, 1, n) cin >> a[i];
    fto1 (i, 0, 60) cnt[i] = 0;

    fto (i, 1, n) {
        fto1 (j, 0, 60) {
            if (a[i] & (1LL << j)) {
                ++cnt[j];
            }
        }
    }

    ll ans = 0;
    fto (i, 1, n) {
        ll AND = 0;
        ll OR = (a[i] % oo)*n % oo;
        fto1 (j, 0, 60) {
            if (a[i] & (1LL << j)) {
                AND += ((1LL << j) % oo)*cnt[j];
                AND %= oo;
            }
            else {
                OR += ((1LL << j) % oo)*cnt[j];
                OR %= oo;
            }
        }
        ans += (AND * OR) % oo;
        ans %= oo;
    }

    bug(ans);
}

int main() {
    #ifdef _LOCAL
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    if (multi_test) cin >> t;
    while (t--) {
        _main();
    }

    #ifdef _LOCAL
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}
