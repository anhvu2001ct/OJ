#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
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
#define bug(...) _bug(cout, __VA_ARGS__)
#define bugn(...) _bugn(#__VA_ARGS__, __VA_ARGS__)
#define buga(a, s, e) cout << '{'; fto (__i, s, e) cout << a[__i] << " }"[__i == e]; cout << endl

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
    return os << '(' << v.ff << ", " << v.ss << ')';
}

template<typename T>
void _bug(ostream &os, T const &var) { os << var << endl; }

template<typename T, typename... Args>
void _bug(ostream &os, T const &var, Args const &... args) {
    os << var << ' ';
    _bug(os, args...);
}

template<typename... Args>
void _bugn(string const &s, Args const &... args) {
    auto split = [](string const &s, string const &delim) {
        int next, pos = 0;
        vector<string> res;
        while (1) {
            next = s.find(delim, pos);
            if (next == string::npos) break;
            res.push_back(s.substr(pos, next-pos));
            pos = next+sz(delim);
        }
        res.push_back(s.substr(pos));
        return res;
    };

    ostringstream os; _bug(os, args...);
    string tmp = os.str(); tmp.pop_back(); 
    vector<string> v1 = split(s, ", "), v2 = split(tmp, " ");
    fto1 (i, 0, sz(v1)) cout << '[' << v1[i] << ": " << v2[i] << "]" << " \n"[i == sz(v1)-1];
}

double const pi = acos(-1);
#define oo 1000000007
#define OO 1000000000000000003LL
int const maxn = 2e5+3;

int n;
int a[maxn], L[maxn], R[maxn];
map<int, vector<int>> place;
map<int, set<int>> pos;
deque<int> dq;

void push(int idx) {
    while (!dq.empty() && a[dq.back()] > a[idx]) {
        R[dq.back()] = idx-1;
        dq.pop_back();
    }
    L[idx] = dq.empty() ? 1 : dq.back()+1;
    dq.push_back(idx);
}

#define multi_test 1
void _main() {
    cin >> n;
    place.clear();
    pos.clear();
    fto (i, 1, n) {
        cin >> a[i];
        place[a[i]].push_back(i);
        push(i);
    }
    while (!dq.empty()) R[dq.back()] = n, dq.pop_back();
    fto (i, 1, n) if (L[i] > 1 && a[L[i]-1] == a[i]) L[i] = L[L[i]-1];
    int maxi = -oo;
    fdto (i, n, 1) {
        maxi = max(maxi, a[i]);
        pos[maxi].insert(i);
    }
    maxi = -oo;
    fto (i, 1, n) {
        maxi = max(maxi, a[i]);
        int x = upper_bound(all(place[maxi]), i) - place[maxi].begin();
        if (x == sz(place[maxi])) continue;
        x = place[maxi][x];
        if (L[x] <= i+1) {
            auto j = pos[maxi].upper_bound(R[x]+1);
            if (j == pos[maxi].begin()) continue;
            --j;
            if (*j == x) continue;
            bug("YES");
            bug(i, (*j)-i-1, n-(*j)+1);
            return;
        }
    }
    bug("NO");
}

int main() {
    #ifdef KITTENS
        freopen("main.inp", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    if (multi_test) cin >> t;
    while (t--) {
        _main();
    }

    #ifdef KITTENS
        cerr << 0.001*clock() << endl;
    #endif
    return 0;
}