#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
const ll M=998244353;
const ll N=1000005,E=524288;

long long t, MOD; //10e5
long long n; //10e12



ll binomialCoeff(ll n, ll r)
{
    if (r > n) return 0;
    vector< ll > inv (r+1, 0);
    inv[0] = 1;
    if(r+1>=2)
    inv[1] = 1;
 
    for (ll i = 2; i <= r; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }
    ll ans = 1;
    for (ll i = 2; i <= r; i++) {
        ans = ((ans % MOD) * (inv[i] % MOD)) % MOD;
    }
    for (ll i = n; i >= (n - r + 1); i--) {
        ans = ((ans % MOD) * (i % MOD)) % MOD;
    }
    return ans;
}

// Sol: C(n, 2n-1)
//TODO: make sure all variables get reset
void run_case(){
    cin>>t>>MOD;
    for (ll i = 0; i<t; i++){
        cin>>n;
        cout<<binomialCoeff(2*n-1, n)<<endl;
    }
}

int main() {
    init_code();
    run_case();
    return 0;
}






