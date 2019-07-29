#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T, Cmp = less<T>>
using oss = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;

char __c;
template<class T> bool scan(T &val) {
    for (__c = getchar(); __c != '-' && __c != EOF && (__c < '0' || __c > '9'); __c = getchar()); if (__c == EOF) return 0;
    bool neg = (__c == '-'); if (neg) val = 0; else val = __c - '0';
    for (__c = getchar(); __c >= '0' && __c <= '9'; __c = getchar()) val = val*10 + __c - '0';
    if (neg) val = -val; return 1;
}
bool scan(char &c) { c = getchar(); return c != EOF; }
bool scan(string &s) {
	s = ""; for (__c = getchar(); __c == ' ' || __c == '\n'; __c = getchar()); if (__c == EOF) return 0;
	s += __c; for (__c = getchar(); __c != ' ' && __c != '\n' && __c != EOF; __c = getchar()) s += __c; return 1;
}
template<class T, class... Args> bool scan(T &val, Args&... args) { scan(val); return scan(args...); }