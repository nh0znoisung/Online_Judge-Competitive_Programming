#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required
// using namespace __gnu_pbds; //required 
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
const int maxN = 2e5 + 11;
int st[4*maxN], arr[maxN], n, x;
// Remain element in tree (sum)
void build(int id = 1, int l = 1, int r = n){
    if(l == r){
        st[id] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] + st[id*2+1];
}

void query(int idx, int id = 1, int l = 1, int r = n){
    if(l == r){
        // cout<<l<<endl;
        st[id] = 0;
        cout<<arr[l]<<" ";
        return;
    }
    int mid = (l+r)/2;
    if(st[id*2] > idx) {
        // cout<<"Left: "<<idx<<endl;
        query(idx,id*2,l,mid);
    }
    else {
        // cout<<"Right: "<<idx-st[id*2]<<endl;
        query(idx-st[id*2], id*2+1, mid+1,r);
    }

    st[id] = st[id*2] + st[id*2+1];
}

//TODO: make sure all variables get reset
void run_case(){
    cin>>n;
    for1(i,n) cin>>arr[i];
    build();
    for0(i,n){
        cin>>x;
        query(x-1);
    }
}

int main() {
    init_code();
    int t = 1;
    // cin>>t;
    while(t--){
        run_case();
    }
    return 0;
}