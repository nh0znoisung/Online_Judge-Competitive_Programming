
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>


// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' <<p.first<<", "<<p.second<<')';}

void dbg_out(){cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr<<' '<<H; dbg_out(T...);}
#ifdef NEAL_DEBUG
#define dbg(...) cerr<<"("<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void init_code(){
    ios_base::sync_with_stdio(false);
    #ifndef NEAL_DEBUG
        cin.tie(0);
    #endif
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}
const int M=998244353;
const int N=10012,E=524288;

// int get(vector<int>&v){ //len >= 1
//     int c = 1, curr = v[0], n = v.size(), ans = 1;
//     for(int i = 1; i<n; i++){
//         if(v[i] > curr) c++;
//         else {
//             ans = max(ans, c);
//             c = 1;
//         }
//     }
//     return c;
// }

vector<bool>vis;
int a[N], u,v;
//TODO: make sure all variables get reset
void run_case(){
    int n,m; cin>>n>>m;
    vector<vector<int> > e(n, vector<int>());
    vis.assign(n, false);
    for0(i,n){
        cin>>a[i];
    }
    for0(i,m){
        cin>>u>>v;
        u--; v--;
        e[u].pb(v);
        e[v].pb(u);
    }
    
    for0(i,n){
        if(vis[i]) continue;
        int root = i;
        queue<int>q;
        vector<int>d;
        d.pb(i);
        for(auto&x: e[root]){
            q.push(x);
        }
        vis[root] = true;
        while(!q.empty()){
            int curr = q.front(); 
            d.pb(curr);
            q.pop();
            if(vis[curr]) continue;
            vis[curr] = true;
            for(auto&x: e[curr]){
                if(vis[x]) continue;
                q.push(x);
            }
        }

        vector<int> dd(d.size());
        for0(i,d.size()){
            dd[i] = a[d[i]];
        }
        
        sort(dd.begin(), dd.end());
        for0(i,d.size()){
            a[d[i]] = dd[i];
        }

        d.clear();
        dd.clear();
    }
    // for0(i,n){
    //     cout<<a[i]<<" ";
    // }
    // get longest increasing
    int c = 1, curr = a[0], ans = 1;
    for(int i = 1; i<n; i++){
        // cout<<a[i]<<" ";
        if(a[i] > curr) c++;
        else {
            ans = max(ans, c);
            c = 1;
        }
        curr = a[i];
    }
    // cout<<endl;
    cout<<ans<<endl;
}

int main() {
    init_code();
    run_case();
    return 0;
}