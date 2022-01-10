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
// const int N=1000005,E=524288;

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
const int N = 30; //2^30 > 1e9
vector<int> arr(N, 0);
int n;
vector<int> v;
string int_to_bina(int n){
    string s;
    for(int i = 0; i<N; i++){
        s.insert(0, 1, (n%2)+'0');
        n /= 2;
    }
    return s;
}
//TODO: make sure all variables get reset
void run_case(){
    string s;
    arr = vector<int>(N, 0);
    for(int i = 0; i<n; i++){
        s = int_to_bina(v[i]);
        // cout<<s<<" ";
        for(int j = 0; j<N; j++){
            if(s[j] == '1') arr[j]++;
        }
    }
    // for(int i = 0; i<N; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int ans = 0;
    for(int i = 0; i<N; i++){
        ans *= 2;
        if(arr[i] >= 2) ans += 1;
    }
    cout<<ans<<endl;
}
 
int main() {
   init_code();
   int t;
   cin>>t;
   while(t--){
       cin>>n;
       v = vector<int>(n);
       for0(i,n){
           cin>>v[i];
       }
        run_case();
        v.clear();
   }
   return 0;
}