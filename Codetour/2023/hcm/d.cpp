#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
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

// priority_queue
ll n,k, val, res;
double r, xx, yy, zz, x,y,z, dist;

// radius, value
struct cmp {
    bool operator()(const std::pair<double, ll>& p1, const std::pair<double, ll>& p2) const {
        return p1.first > p2.first;
    }
};

double calc(double x0, double y0, double z0, double x, double y, double z) {
    double dx = x - x0;
    double dy = y - y0;
    double dz = z - z0;
    return sqrt(dx * dx + dy * dy + dz * dz);
}


//TODO: make sure all variables get reset
void run_case(){
    cin>>n>>k>>r>>xx>>yy>>zz;
    priority_queue< pair<double,ll>, vector<pair<double, ll> >, cmp > pq; // radius + val
    for (int i = 0; i<n; i++){
        cin>>x>>y>>z>>val;
        dist = calc(x, y, z, xx, yy, zz);;
        pq.push( make_pair(dist, val) );
    }
    // Get top K and radius <= R
    int count = 0;
    res = 0;
    //debug
    // cout<<pq.size()<<endl;
    while (!pq.empty()) {
        auto ele = pq.top();
        dist = ele.first;
        val = ele.second;
        //debug
        // cout<< dist << " "<< val<<endl;
        
        if(dist > r) break;

        res += val;
        count++;

        if(count == k) break;
        pq.pop(); 
    }
    cout<<res<<endl;
}

int main() {
    init_code();
    run_case();
    return 0;
}