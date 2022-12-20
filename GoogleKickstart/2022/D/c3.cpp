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
const int M=998244353;
const int N=2520,E=524288;

//TODO: make sure all variables get reset
void run_case(int t){
    cout<<"Case #"<<t<<": ";
    ll n; cin>>n;
    vector<ll>s(n);
    for0(i,n) cin>>s[i];
    ll m; cin>>m;
    vector<ll>k(m);
    vector<unordered_set<ll>>h(N);
    unordered_set<ll> us;
    for0(i,m){
        cin>>k[i];
        us.insert(k[i]);
        h[k[i]].insert(i);
    }
    vector<vector<ll>>left(m, vector<ll>(N, -1)); //(m,N,(left_idx,right_idx))
    vector<vector<ll>>right(m, vector<ll>(N, -1)); //(m,N,(left_idx,right_idx))
    for(ll i=0; i<m; i++){
        for(ll j=i; j<m; j++){
            if(right[i][k[j]] == -1) right[i][k[j]] = j;
        }
    }
    for(ll i=m-1; i>=0; i--){
        for(ll j=i; j>=0; j--){
            if(left[i][k[j]] == -1) left[i][k[j]] = j;
        }
    }
    // O(N*M^2) -> O(N*M) | Nearsest left, right 
    //Dp: end at char n, with pos of keyboard in m
    //ll_MAX if char n-th not in m-th pos
    // dp[n][x] = 
    vector<vector<ll>>dp(n, vector<ll>(m, INT_MAX));
    for(ll i=0; i<m; i++){
        if(h[s[0]].count(i)) dp[0][i] = 0;
    }
    for(ll i=1; i<n; i++){
        //check not in m-th pos
        for(ll j=0; j<m; j++){
            if(h[s[i]].count(j)) {
                // pair<ll,ll> p = hh[j][s[i-1]];
                ll l = left[j][s[i-1]], r = right[j][s[i-1]];
                if(l != -1){
                    dp[i][j] = min(dp[i][j], (ll)dp[i-1][l] + abs(l-j));
                    // cout<<i-1<<" "<<l<<" "<<(ll)dp[i-1][l] + abs(l-j)<<endl;
                }
                if(r != -1){
                    dp[i][j] = min(dp[i][j], (ll)dp[i-1][r] + abs(r-j));
                    // cout<<i-1<<" "<<r<<" "<<(ll)dp[i-1][r]<<endl;
                }
            }
        }
    }
    ll ans = dp[n-1][0];
    for(ll i=1; i<m; i++){
        ans = min(ans, dp[n-1][i]);
    }
    cout<<ans<<endl;

    // for0(i,m){
    //     for(auto j: us){
    //         cout<<i<<" "<<j<<" :"<<left[i][j]<<" "<<right[i][j]<<endl;
    //     }
    // }
    
    // for0(i,n){
    //     for0(j,m){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

int main() {
    init_code();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        run_case(i);
    }
    return 0;
}