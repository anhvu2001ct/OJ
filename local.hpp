#include <bits/stdc++.h>

#define forit(it, x) for (auto it = (x).begin(); it < (x).end(); ++it)
#define debug(...) cout << tuple(__VA_ARGS__) << '\n'

using namespace std;

template<class T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    os << '[';
    forit (it, vec) os << (it == vec.begin() ? "" : ", ") << *it;
    os << ']';
    return os;
}

template<class TupType, size_t... I>
void print_tuple(ostream& os, const TupType& tup, std::index_sequence<I...>)
{
    os << '(';
    (..., (os << (I == 0 ? "" : ", ") << get<I>(tup)));
    os << ')';
}

template<class... T>
ostream& operator<<(ostream& os, const tuple<T...>& tup)
{
    print_tuple(os, tup, make_index_sequence<sizeof...(T)>());
    return os;
}
