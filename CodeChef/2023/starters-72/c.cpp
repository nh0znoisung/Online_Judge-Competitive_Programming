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
const int N=1e5+11,E=524288;

int n , a[N],dp[N+2],pref[N];
// vector<vector<int>>edges;
// vector<bool>vis;
//TODO: make sure all variables get reset
// void dfs(){

// }

void run_case(){
    cin>>n;
    for0(i,n) cin>>a[i];
    fill_n(dp,n+3,-1);
    // edges.resize(n+2);
    int cur = 0;
    map<int,vector<int> >um;
    pref[0] = 0;
    for1(i,n){
        if(a[i-1] == 0) cur--;
        else cur++;
        pref[i] = cur;
        // cout<<cur<<endl;
        um[cur].push_back(i);
    }

    for(auto i: um){
        cout<<i.first<<": ";
        for (int j: i.second) cout<<j<<" ";
        cout<<endl;
    }

    int tar, mx = 0;
    dp[n+1] = 0;
    for(int i = n; i>0; i--){
        tar = cur - pref[i-1];
        for(int j: um[tar]){
            if(j >= i){
                dp[i] = max(dp[j+1]+1,dp[i]);
                cout<<"Index: "<<i<<" Value: "<<dp[i]<<" Refer: "<<j+1<<endl;
                mx = max(mx,dp[i]);
            }
        }
        // if(a[i] == 0) tar++;
        // else tar--;
    }
    cout<<mx<<endl;



}

int main() {
    init_code();
    int t;
    cin>>t;
    while(t--){
        run_case();
    }
    return 0;
}