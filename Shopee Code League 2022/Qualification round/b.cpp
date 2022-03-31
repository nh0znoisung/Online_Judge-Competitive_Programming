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

//TODO: make sure all variables get reset


int maxSum(int a[], int n)
{
    // sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
 
    int limit = 2 * sum + 1;
 
    // bottom up lookup table;
    int dp[n + 1][limit];
 
    // initialising dp table with INT_MIN
    // where, INT_MIN means no solution
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < limit; j++)
            dp[i][j] = INT_MIN;
    }
 
    // Case when diff is 0
    dp[0][sum] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < limit; j++) {
 
            // Putting ith element in g0
            if ((j - a[i - 1]) >= 0 && dp[i - 1][j - a[i - 1]] != INT_MIN)
 
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]]
                                             + a[i - 1]);
 
            // Putting ith element in g1
            if ((j + a[i - 1]) < limit && dp[i - 1][j + a[i - 1]] != INT_MIN)
 
                dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i - 1]]);
 
            // Ignoring ith element
            if (dp[i - 1][j] != INT_MIN)
 
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
 
    return dp[n][sum];
}

int main() {
   init_code();
   int t;
   cin>>t;
    int arr[t];
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    cout<<maxSum(arr,t)<<endl;
   return 0;
}