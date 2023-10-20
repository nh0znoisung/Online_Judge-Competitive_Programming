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
const int maxN = 2e5 + 11; //1e9 max ele

int arr[maxN], n,q,type,a,b;
ll st[4*maxN];

void build(int id = 1, int l = 1, int r = n){
    if(l == r){ // stop case
        st[id] = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] + st[id*2+1];
}

// arr[k] = u
void update(int k, int u, int id = 1, int l = 1, int r = n){
    if(k < l || k > r){ // outside the range
        return;
    }

    if(l == r){ //stop case
        st[id] = u;
        return;
    }
    int mid = (l + r) >> 1;
    update(k,u,id*2,l,mid);
    update(k,u,id*2+1,mid+1,r);

    st[id] = st[id*2] + st[id*2+1];
}

ll get(int a, int b, int id = 1, int l = 1, int r = n){
    if(a > r || b < l){ // not intersect
        return 0;
    }

    if(a <= l && r <= b){ // bounding
        return st[id];
    }
    int mid = (l + r) >> 1;
    return get(a,b,id*2,l,mid) + get(a,b,id*2+1,mid+1,r);
}

//TODO: make sure all variables get reset
void run_case(){
    cin>>n>>q;
    for1(i,n) cin>>arr[i];
    build();

    while(q--){
        cin>>type>>a>>b;
        if(type == 1){
            arr[a] = b;
            update(a,b);
        }else if(type == 2){
            cout<<get(a,b)<<endl;
        }
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