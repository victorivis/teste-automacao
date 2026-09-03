// https://codeforces.com/contest/2036/problem/E

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define is insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define unique(x) (x).erase(unique((x).begin(), (x).end()), (x).end())
#define f(i,b,e) for (int i = (b); i < (e); ++i)
#define rf(i,b,e) for (int i = (b); i >= (e); --i)
#define fa(i,a) for (auto& i : (a))
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define mkp make_pair
#define mark if(info)

using namespace std;
using namespace __gnu_pbds;

bool info = false;

using par = array<int,2>;
using ii = pair<int,int>;
using iii = array<int,3>;

void print_value(const par& v) {cout << "(" << v[0] << " " << v[1] << ")"; }
void print_value(const iii& v) {cout << "(" << v[0] << " " << v[1] << " " << v[2] << ")"; }
 
template<typename T>
void print_value(const T& v) { cout << v; }
 
template<typename A, typename B>
void print_value(const pair<A,B>& p) {
    cout << "(";
    print_value(p.first);
    cout << " ";
    print_value(p.second);
    cout << ")";
}
 
template<typename T>
void print_value(const vector<T>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        print_value(v[i]);
    }
    cout << "]";
}
 
template<typename T>
concept Iterable = requires(T t) {
    begin(t);
    end(t);
};
 
template<Iterable T>
requires (!is_same_v<T, string>)
void print_value(const T& v) {
    cout << "[";
    bool first = true;
    for (const auto& x : v) {
        if (!first) cout << ", ";
        first = false;
        print_value(x);
    }
    cout << "]";
}
 
template<typename T, typename... Args>
void debug_out(const char* names, T value, Args... args) {
    if (!info) return;
    const char* comma = strchr(names, ',');
    if (comma) {
        cout.write(names, comma - names) << "=";
        print_value(value);
        cout << " ";
        if constexpr (sizeof...(args) > 0)
            debug_out(comma + 1, args...);
        else
            cout << '\n';
    } else {
        cout << names << "=";
        print_value(value);
        cout << '\n';
    }
}
 
#define dbg(...) debug_out(#__VA_ARGS__, __VA_ARGS__)

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool all_test = 0;

const int MAXN = 2e5 + 1, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> a(k, vector<int>(n));

    dbg(n,k,q);

    f(i,0,n){
        f(j,0,k){
            cin >> a[j][i];
        }
    }

    f(i,0,a.size()){
        int acc = 0;
        
        f(j,0,a[i].size()){
            acc |= a[i][j];
            a[i][j] = acc;
        }
        dbg(a[i]);
    }

    f(i,0,q){
        int qq; cin >> qq;

        par lim = {0,n-1};
        f(j,0,qq){
            int x,y; char c;
            cin >> x >> c >> y;
            dbg(x,c,y);
            x--;

            if(c=='<'){
                int pos = lower_bound(all(a[x]), y) - a[x].begin() - 1;
                lim[1] = min(lim[1], pos);
            }
            else{
                int pos = upper_bound(all(a[x]), y) - a[x].begin();
                lim[0] = max(lim[0], pos);
            }
        }

        dbg(lim);
        if(lim[0] <= lim[1]){
            cout << lim[0]+1 << "\n";
        }
        else{
            cout << "-1\n";
        }
        // cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    if (all_test) cin >> tc;
    while (tc--) solve();
    return 0;
}