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

int n, a[N], pref[N], suff[N];
//TODO: make sure all variables get reset
void run_case(){
    cin>>n;
    int x = 0;
    for0(i,n){
        cin>>a[i];
        x ^= a[i];
    }
    // cout<<(4^5^6^7^8)<<endl;
    pref[0] = a[0];
    suff[n-1] = a[n-1];
    for(int i = 1; i<n; i++) pref[i] = pref[i-1] ^ a[i];
    for(int i = n-2; i>=0; i--) suff[i] = suff[i+1] ^ a[i];
    if(n%2 == 1) {
        cout<<"YES"<<endl;
        return;
    }
    // even
    bool ok = false;
    for0(i,n){
        if(i%2 == 0){
            if(pref[i] == a[i] && suff[i+1] == a[i]) {
                ok = true;
                // cout<<a[i]<<endl;
                break;
            }
        }else{
            if(pref[i-1] == a[i] && suff[i] == a[i]) {
                ok = true;
                // cout<<a[i]<<endl;
                break;
            }
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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