#include <bits/stdc++.h>

using namespace std;

#define bugn(...) _bugn(cerr, #__VA_ARGS__, __VA_ARGS__)

template<typename T>
void __bug(ostream &os, T const &var) { os << var << '\n'; }

template<typename T, typename... Args>
void __bug(ostream &os, T const &var, Args const &... args) {
    os << var << "||";
    __bug(os, args...);
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

    ostringstream os; __bug(os, args...);
    string tmp = os.str(); tmp.pop_back();
    vector<string> v1 = split(s, ", "), v2 = split(tmp, "||");
    for (int i = 0; i < v1.size(); ++i) out << '[' << v1[i] << ": " << v2[i] << "]" << " \n"[i == v1.size()-1];
}

