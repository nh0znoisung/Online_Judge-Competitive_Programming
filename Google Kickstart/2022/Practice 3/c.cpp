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
const int N=5e4 + 23,E=524288;
int n,r,c,sr,sc;

string s;

//TODO: make sure all variables get reset
void run_case(int l, unordered_map<char, pair<int,int>>& um){

    cout<<"Case #"<<l<<": ";
    cin>>n>>r>>c>>sr>>sc;
    sr--; sc--;
    vector<vector<bool>>vis(r, vector<bool>(c, false));
    cin>>s;
    vis[sr][sc] = true;
    // for0(i,n) cout<<um[s[i]].first<<" ";
    for0(i, n){
        sr += um[s[i]].first;
        sc += um[s[i]].second;
        while(vis[sr][sc]){
            sr += um[s[i]].first;
            sc += um[s[i]].second;
        }
        vis[sr][sc] = true;
    }
    cout<<sr + 1<<" "<< sc + 1<<endl;
}

int main() {
    init_code();
    unordered_map<char, pair<int,int>> um;
    um['E'] = {0,1};
    um['W'] = {0,-1};
    um['N'] = {-1,0};
    um['S'] = {1,0};
    int t;
    cin>>t;
    for1(i,t){
        run_case(i, um);
    }
    return 0;
}