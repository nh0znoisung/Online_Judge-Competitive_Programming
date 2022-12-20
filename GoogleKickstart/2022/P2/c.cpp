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
const int N=1000005,E=524288;

vector<int> a[100001];

bool check(vector<int>& a, vector<int>& b){
    // for(int i: a) cout<<i<<" ";
    // cout<<endl;
    // for(int i: b) cout<<i<<" ";
    // cout<<endl;
    bool ok = false;
    for(int i = 0; i<26; i++){
        if( (a[i] - b[i]) %2 == 1){
            if(!ok) ok = true;
            else return false;
        }
    }
    return true;
}
int m, q,x,y, ans;
//TODO: make sure all variables get reset
void run_case(int n){
    cin>>m>>q;
    ans = 0;
    string s; cin>>s;
    vector<int>v(26,0);
    a[0] = v;
    for(int i = 1; i<=m; i++){
        v[s[i-1] - 'A']++;
        // for(int j: v) cout<<j<<" ";
        // cout<<endl;
        a[i] = v;
    }
    // for(int i = 0; i<=m; i++){
    //     for(int j: a[i]) cout<<j<<" ";
    //     cout<<endl;
    // }
    while(q--){
        cin>>x>>y;
        if(check(a[y], a[x-1])) ans++;
    }
    cout<<"Case #"<<n<<": "<<ans<<endl;

}

int main() {
    // init_code();
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        run_case(i);
    }
    return 0;
}
