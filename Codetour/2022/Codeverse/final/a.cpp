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
const int N=10009,E=524288;
int d,c, a[N], b[N], cnt;
vector<int>dx = {0,-1,1,0};
vector<int>dy = {-1,0,0,1};
vector<bool>vis;
int get(int x, int y){
    return x*c+y;
}
pair<int,int> get(int x){
    return {x/c,x%c};
}
void bfs(int x, vector<vector<int>>& e){
    for(int i: e[x]){
        if(!vis[i]){
            vis[i] = true;
            a[i] = cnt;
            bfs(i, e);
        }
    }
}
//TODO: make sure all variables get reset
void run_case(int kk){
    cout<<"BD #"<<kk<<":"<<endl;
    cin>>d>>c;
    vector<vector<int>>e(c*d, vector<int>());
    // vector<bool>vis(c*d, false);
    vis.assign(c*d, false);
    for0(i,d){
        for0(j, c){
            cin>>a[i*c+j];
            b[i*c+j] = i*c + j;
        }
    }
    for0(i, d){
        for0(j ,c){
            int x = i, y = j;
            int mn = 1e5+12, idx = -1;
            for0(k, 4){
                int nx = x+dx[k], ny = y+dy[k];
                if(nx>=0 && nx<d && ny>=0 && ny<c){
                    if(a[get(x,y)]>a[get(nx,ny)] &&  a[get(nx,ny)] < mn){
                        mn = a[get(nx,ny)];
                        idx = k;
                    }
                }
            }
            if(idx != -1){
                int nx = x+dx[idx], ny = y+dy[idx];
                int l = get(nx,ny), r = get(x,y);
                e[l].pb(r);
            }
        }
    }
    cnt = 0;
    for0(i, c*d){
        if(e[i].size() == 0){
            vis[i] = true;
            a[i] = cnt;
            bfs(i, e);
            cnt++;
        }
    }
    unordered_map<int,int>um;
    int count = 0;
    for0(i,c*d){
        if(um.count(a[i]) == 0){
            um[a[i]] = count;
            count++;
        }
    }
    for0(i, c*d){
        cout<<um[a[i]] + 'a'<<" ";
        if(i + 1 % c == 0) cout<<endl;
    }
}

int main() {
    init_code();
    int t;
    cin>>t;
    for1(i, t) run_case(i);
    return 0;
}