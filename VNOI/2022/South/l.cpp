
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
const int N=1005,E=524288;
int n, more[N],carry[N],dp[N];
string a,b,c;
int x,y,z;
//TODO: make sure all variables get reset
void run_case(){
    while(true) {
        cin>>n;
        if(n==0) break;
        cin>>a>>b>>c;
        for0(i,n){
            x=a[i]-'0';
            y=b[i]-'0';
            z=c[i]-'0';
            if(x+y>=10) carry[i] = 1;
            else carry[i] = 0;

            if(z == (x+y)%10 || z == (x+y+1)%10) {
                more[i] = z - (x+y)%10;
            }else{
                more[i] = -1;
                carry[i] = -1;
            }
        }
        ll res = 0;
        bool in = false;
        ll X=0,Y=0,Z=0, A=0,B=0;
        stack<pair<int,int> >st;
        for0(i,n){
            if(more[i] == 0 && carry[i] == 0){
                if(in) X++;
                else res++;
            }else if(more[i] == 1&& carry[i] == 0){
                if(!in){
                    in = true;
                }else{
                    st.push(pair<int,int>(X,Y));
                    X=0;
                    Y=0;
                }

            }else if(more[i] == 1 && carry[i] == 1){
                if(in) Y++;
            }else if(more[i] == 0 && carry[i] == 1){
                if(in){
                    in = false;
                    st.push(pair<int,int>(X,Y));
                    X=0;
                    Y=0;

                    A=0;B=2;
                    while(!st.empty()){
                        auto p = st.top();
                        st.pop();
                        B += p.se;
                        A += p.fi;
                        A = max(A,B);
                    }
                    res += A;
                    st = stack<pair<int,int> >();
                }
            }
        }
        while(!st.empty()){
            auto p = st.top();
            st.pop();
            B += p.se;
            res += p.fi;
        }
        cout<<n-res<<endl;
    }
}

int main() {
    init_code();
    run_case();
    return 0;
}