#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i
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
const int M=998244353;
const int N=1000005,E=524288;
 
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
 
 
int minDistance(const vector<int>& dist, const vector<bool>& sptSet)
{   
    int min = INT_MAX, min_index;
    int V = dist.size();
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
 
void dijkstra(const vector<vector<int>>&graph, int src)
{
    int V = graph.size();
    vector<int> dist(V);
    vector<bool> sptSet(V); 
 
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    dist[src] = 0;
 
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
 
        sptSet[u] = true;
 
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout<<dist[V-1];
}
 
int n, m,x;
int main() {
    init_code();
    cin>>n>>m;
 
    vector<vector<int>>edges;
    map<pair<int,int>,int>um;
    vector< vector< pair<int,int>>>mp(255);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>x;
            if(x > 0 || (i == 0 && j == 0) || (i == n-1 && j == m-1)){
                um[{i,j}] = edges.size();
                edges.pb({i,j});
            }
            if(x > 0){
                mp[x-1].pb({i,j});
            }
        }
    }
 
    int l = edges.size();
    vector<vector<int>> graph(l, vector<int>(l, -1));
    
    for(int i = 0; i<l; i++){
        graph[i][i] = 0;
    }
 
    for(int i =0; i<255; i++){
        for(int j = 0; j<mp[i].size(); j++){
            int u = um[mp[i][j]];
            for(int k = j+1; k<mp[i].size(); k++){
                int v = um[mp[i][k]];
                graph[u][v] = 0;
                graph[v][u] = 0;
            }
        }
    }
 
    for(int i =0; i<l; i++){
        for(int j = i+1; j<l; j++){
            if(graph[i][j] == -1){
                graph[i][j] = abs(edges[i][0] - edges[j][0]) + abs(edges[i][1] - edges[j][1]);
                graph[j][i] = abs(edges[i][0] - edges[j][0]) + abs(edges[i][1] - edges[j][1]);
            }
        }
    }
 
    dijkstra(graph, 0);
   return 0;
}
