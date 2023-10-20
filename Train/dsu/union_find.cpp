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

int parent[N], sz[N], height[N];
void make_set(int v){
    parent[v] = v; // parent of node is self-loop
    sz[v] = 1; //size of set
    height[v] = 0; //root with 0 height
}

int find_set(int v){ // find the asendants of node
    if(parent[v] == v) return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b){ //union sets
    a = find_set(a);
    b = find_set(b);
    // if(a != b) parent[a] = b; //too simple => parent is node with height or size

    //size
    if (a != b){
        if(sz[a] > sz[b]) swap(a,b); //sz[b] > sz[a] -> b is parent of a
        parent[a] = b;
        sz[b] += sz[a];
    }

    //height
    if(a != b){
        if(height[a] > height[b]) swap(a,b); //b > a -> b is parent of a
        parent[a] = b; // height[b] >= height[a]
        if(height[a] == height[b]) height[b]++;
    }

}


//TODO: make sure all variables get reset
void run_case(){

}

int main() {
    init_code();
    int t;
    t = 1;
    while(t--){
        run_case();
    }
    return 0;
}