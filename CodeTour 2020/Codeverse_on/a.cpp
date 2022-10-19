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
int x,y;
ll cnt;
vector<bool>vis;
vector<bool>in;
void bfs(int s, vector<vector<int>>&e){
    for(int i: e[s]){
        if(!vis[i]){
            vis[i]=true;
            bfs(i,e);
        }
    }
}
//TODO: make sure all variables get reset
void run_case(){
    int n,e; cin>>n>>e;
    vector<vector<int>>edges(n);
    in.assign(n, false);
    for0(i, e){
        cin>>x>>y;
        if(x != y){ // ?????????
            edges[x-1].push_back(y-1);
            in[y-1]=true;
        }
        
    }
    int tar; cin>>tar;
    tar--;
    vis.assign(n, false);
    vis[tar] = true;
    bfs(tar, edges);
    cnt=0;
    for0(i,n){
        if(!vis[i] && !in[i]){
            vis[i] = true;
            bfs(i, edges);
            // cout<<i<<endl;
            cnt++;
        }
    }
    for0(i,n){
        if(!vis[i]){
            vis[i] = true;
            bfs(i, edges);
            // cout<<i<<endl;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    // for0(i,n) cout<<vis[i]<<" ";
    // cout<<endl;
    // for0(i,n) cout<<in[i]<<" ";
}

int main() {
    init_code();
    run_case();
    return 0;
}