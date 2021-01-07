#include <bits/stdc++.h>

using namespace std;

#define bugn(...) _bugn(cout, #__VA_ARGS__, __VA_ARGS__)

template<typename T>
void _bug(ostream &os, T const &var) { os << var << '\n'; }

template<typename T, typename... Args>
void _bug(ostream &os, T const &var, Args const &... args) {
    os << var << "||";
    _bug(os, args...);
}

template<typename... Args>
void _bugn(ostream &out, string const &s, Args const &... args) {
    auto split = [](string const &s, string const &delim) {
        int next, pos = 0;
        vector<string> res;
        while (1) {
            next = s.find(delim, pos);
            if (next == string::npos) break;
            res.push_back(s.substr(pos, next-pos));
            pos = next+delim.size();
        }
        res.push_back(s.substr(pos));
        return res;
    };

    ostringstream os; _bug(os, args...);
    string tmp = os.str(); tmp.pop_back();
    vector<string> v1 = split(s, ", "), v2 = split(tmp, "||");
    for (int i = 0; i < v1.size(); ++i) out << '[' << v1[i] << ": " << v2[i] << "]" << " \n"[i == v1.size()-1];
}

template<class T1, class T2> ostream& operator<<(ostream &os, pair<T1, T2> const &v) {
    return os << '(' << v.first << ", " << v.second << ')';
}

template<class T> void cout_container(ostream &os, T const &container) {
    if (container.empty()) {
        os << "{}";
        return;
    }
    os << '{';
    auto cur = container.begin();
    for (int cnt = 0; cnt < container.size(); ++cnt) os << *(cur++) << " }"[cnt == container.size()-1];
}

template<class T> ostream& operator<<(ostream &os, vector<T> const &container) {
    cout_container(os, container); return os;
}

template<class T> ostream& operator<<(ostream &os, deque<T> const &container) {
    cout_container(os, container); return os;
}

template<class T> ostream& operator<<(ostream &os, set<T> const &container) {
    cout_container(os, container); return os;
}

template<class T> ostream& operator<<(ostream &os, multiset<T> const &container) {
    cout_container(os, container); return os;
}

template<class T1, class T2> ostream& operator<<(ostream &os, map<T1, T2> const &container) {
    cout_container(os, container); return os;
}
