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
const int N=18,E=524288;
int l,r,n,x;
//TODO: make sure all variables get reset
void run_case(){
    cin>>l>>r;
    n = r+1;
    // n = odd => Just return tmp = x
    // n = even ??? lose x when xor
    // Time < O(n^2)

    //  Alternative approach:  (Tourist)
    // From 0-(n-1): Calculate the sigma of i-th bit. 
    // We always have # bit 0s >= # bit 1s. The equation is: n divisible by 2^(i+1)
    // So if i-th bits of x are 1, then it will change 0 -> 1 and 1-> 0.
    // So, just calculate the sigma of i-th bit, if # bit 1s > # bit 0s, i-th bit of x is 1 since the effect on.
    // Note: If bit 1s = bit 0s, then it can be 0 or 1 in i-th bits of x => So it has many solution. (Just default it = 0)
    vector<int>a(N,0);
    for0(i,n){
        cin>>x;
        for0(j,N){
            // Bit manipulation: Get i-th bit of x
            a[j] += (x>>j)&1; // Find the number of bit 1s
        }
    }

    ll ans = 0;
    for0(j,N){
        if(a[j] > n-a[j]){
            ans += 1LL<<j;
        }
    }
    cout<<ans<<endl;
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