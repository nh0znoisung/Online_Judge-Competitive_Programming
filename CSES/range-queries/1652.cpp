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
const int maxN = 1011;
int n,q, arr[maxN][maxN], hor[maxN][maxN], pref[maxN][maxN],x_1,x_2,y_1,y_2;
string s;

void build(){
    for1(i,n){
        for1(j,n){
            hor[i][j] = hor[i][j-1] + arr[i][j];
        }
    }
    for1(j,n){
        for1(i,n){
            pref[i][j] = pref[i-1][j] + hor[i][j];
        }
    }
}

void debug(){
    cout<<"Arr matrix: \n";
    for0(i,n+1){
        for0(j,n+1){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nHorizontal matrix: \n";
    for0(i,n+1){
        for0(j,n+1){
            cout<<hor[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nPrefix matrix: \n";
    for0(i,n+1){
        for0(j,n+1){
            cout<<pref[i][j]<<" ";
        }
        cout<<endl;
    }
}

//TODO: make sure all variables get reset
void run_case(){
    cin>>n>>q;
    for1(i,n){
        cin>>s;
        for1(j,n){
            arr[i][j] = s[j-1] == '*' ? 1 : 0;
        }
    }
    for0(i,n+1){
        arr[i][0] = 0;
        arr[0][i] = 0;
        pref[i][0] = 0;
        pref[0][i] = 0;
        hor[i][0] = 0;
        hor[0][i] = 0;
    }
    build();
    // debug();

    while(q--){
        // cin>>y_1>>x_1>>y_2>>x_2;
        cin>>x_1>>y_1>>x_2>>y_2;
        int res = pref[x_2][y_2] - pref[x_1-1][y_2] - pref[x_2][y_1-1] + pref[x_1-1][y_1-1];
        cout<<res<<endl;
    }
}

int main() {
    init_code();
    int t = 1;
    // cin>>t;
    while(t--){
        run_case();
    }
    return 0;
}