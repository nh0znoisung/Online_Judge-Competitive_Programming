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
int m;
long long int n;
const int MOD = 1e9 + 7;
int dp[1001][2], arr[1001][2];
//TODO: make sure all variables get reset
void run_case(){
    cin>>m>>n;
    // Check the height
    n++;
    int h = 0;
    while(n>0){
        h++;
        n /= 2;
    }
    h--;
    // Init
    for(int i = 1; i<=m ;i++){
        for(int k = 0; k<=1; k++){
            dp[i][k] = 1;
        }
    }

    // Dynamic Programming
    for(int j = 1; j<h; j++){
        for(int i = 1; i<=m ;i++){
            arr[i][0] = 0;
            for(int k = i+1; k<=m ;k++){
                arr[i][0] = ((long long)arr[i][0] + dp[k][1])%MOD;
                arr[i][0] = ((long long)arr[i][0] * arr[i][0])%MOD;
            }

            arr[i][1] = 0;
            for(int k = 1; k<i ;k++){
                arr[i][1] = ((long long)arr[i][1]+ dp[k][0])%MOD;
                arr[i][1] = ((long long)arr[i][1] * arr[i][1])%MOD;
            }
        }
        for(int i = 1; i<=m ;i++){
            dp[i][0] = arr[i][0];
            dp[i][1] = arr[i][1];
        }
    }

    // Module
    int ans = 0;
    for(int i = 1; i<= m; i++){
        ans = ((long long)ans+dp[i][0])%MOD;
    }
    cout<<ans<<endl;
}

int main() {
   init_code();
   int t;
   cin>>t;
   while(t--){
      run_case();
   }
   return 0;
}