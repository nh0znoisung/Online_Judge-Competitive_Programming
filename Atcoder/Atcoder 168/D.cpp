#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;

int minEdgeBFS(vector <int> edges[], int u,
                              int v, int n)
{
    // visited[n] for keeping track of visited
    // node in BFS
    vector<bool> visited(n, 0);

    // Initialize distances as 0
    vector<int> distance(n, 0);

    // queue to do BFS.
    queue <int> Q;
    distance[u] = 0;

    Q.push(u);
    visited[u] = true;
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        for (int i=0; i<edges[x].size(); i++)
        {
            if (visited[edges[x][i]])
                continue;

            // update distance for i
            distance[edges[x][i]] = distance[x] + 1;
            Q.push(edges[x][i]);
            visited[edges[x][i]] = 1;
        }
    }
    return distance[v];
}


void addEdge(vector <int> edges[], int u, int v)
{
   edges[u].push_back(v);
   edges[v].push_back(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector <int> edges[n];
	for(int i = 0; i<m ;i++){
        int a,b;
        cin>>a>>b;
        addEdge(edges, a-1, b-1);
	}
	cout<<"Yes"<<endl;
	for(int i =1; i<n;i++){
        cout << minEdgeBFS(edges, 0, i, n)<<endl;
	}


	return 0;
}
