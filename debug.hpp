#include "validate.hpp"

namespace debug {
    mt19937_64 rg(chrono::steady_clock::now().time_since_epoch().count());

    template<typename T1, typename T2> ostream& operator<< (ostream &os, pair<T1, T2> const &v) {
        return os << v.ff << ' ' << v.ss;
    }

    template<typename T> ostream& operator<< (ostream &os, vector<T> const &vec) {
        fto1 (i, 0, sz(vec)) {
            os << vec[i];
            if (i < sz(vec)-1) os << ' ';
        }
        return os;
    }

    ll rand(ll const &first=0, ll const &last=1e9) {
        return uniform_int_distribution<>(first, last)(rg);
    }

    double randf(double const &first=0, double const &last=1) {
        return uniform_real_distribution<>(first, last)(rg);
    }

    template<class T>
    T rand(vector<T> const &v) {
        return v[rand(0, sz(v)-1)];
    }

    template<typename Type>
    void shuffleVec(vector<Type> &vec) {
        shuffle(all(vec), rg);
    }

    vector<ll> genVec(int n, ll const &l, ll const &r) {
        vector<ll> res(n); fat (&v, res) v = rand(l, r);
        return res;
    }

    vector<ll> genUnique(int n, ll l, ll r) {
        if (r-l+1 < n) return vector<ll>();
        r = r-n+1;
        vector<ll> res(n);
        fto1 (i, 0, n) {
            res[i] = rand(l, r++);
            l = res[i] + 1;
        }
        shuffleVec(res);
        return res;
    }

    vector<int> genPermu(int n) {
        vector<int> res(n); fto1 (i, 0, n) res[i] = i+1;
        shuffleVec(res);
        return res;
    }

    vector<ii> genTree(int n, int root = 1, int minDepth=1) {
        minDepth = max(min(minDepth, n), 1);
        vector<int> node, used(1, root);
        fto (i, 1, n) if (i != root) node.push_back(i);
        shuffleVec(node);
        vector<ii> res;
        static auto push = [&](int from) {
            res.push_back({from, node.back()});
            used.push_back(node.back());
            node.pop_back();
        };
        while (--minDepth) push(used.back());
        while (!node.empty()) push(rand(used));
        shuffleVec(res);
        return res;
    }

    vector<pair<ii, ll>> genWTree(int n, ll const &l, ll const &r, int root=1, int minDepth=1) {
        minDepth = max(min(minDepth, n), 1);
        vector<int> node, used(1, root);
        fto (i, 1, n) if (i != root) node.push_back(i);
        shuffleVec(node);
        vector<pair<ii, ll>> res;
        static auto push = [&](int from) {
            res.push_back({ii(from, node.back()), rand(l, r)});
            used.push_back(node.back());
            node.pop_back();
        };
        while (--minDepth) push(used.back());
        while (!node.empty()) push(rand(used));
        shuffleVec(res);
        return res;
    }

    void makeTest(string problemId, int testId, bool newDir=true, int w=2) {
        auto makeId = [](int id, int width) {
            ostringstream ss; ss << setw(width) << setfill('0') << id;
            return ss.str();
        };
        system(("mkdir " + problemId).c_str());
        string tc = makeId(testId, w);
        string path = problemId + "\\" + tc;
        system(("mkdir " + path).c_str());
        system("main.exe");
        system(("copy main.inp " + problemId + ".inp").c_str());
        system(("copy main.out " + problemId + ".out").c_str());
        system(("move " + problemId + ".inp " + path).c_str());
        system(("move " + problemId + ".out " + path).c_str());
    }
}