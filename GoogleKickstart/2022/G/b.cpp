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
int rs,rh,n,m,x,y;
double nn[9], mm[9];
double min_n = INT_MAX, min_m = INT_MAX;
int cnt_n = 0, cnt_m = 0;
//TODO: make sure all variables get reset
void run_case(int kk){
    cout<<"Case #"<<kk<<": ";
    cin>>rs>>rh>>n;
    min_n = INT_MAX, min_m = INT_MAX;
    cnt_n = cnt_m = 0;
    for0(i,n){
        cin>>x>>y;
        nn[i]=sqrt(x*x+y*y);
        if(nn[i] <= (double)(rs + rh)){
            min_n = min(min_n, nn[i]);
            cnt_n ++;
        }
    }
    cin>>m;
    for0(i,m){
        cin>>x>>y;
        mm[i]=sqrt(x*x+y*y);
        if(mm[i] <= (double)(rs+rh)){
            min_m = min(min_m, mm[i]);
            cnt_m++;
        }
    }
    if(min_n == INT_MAX){
        // Red lose
        cout<<0<<" "<<cnt_m<<endl;
    }else if(min_m == INT_MAX){
        // Yellow lose
        cout<<cnt_n<<" "<<0<<endl;
    }else if(min_n < min_m){
        // Red win
        int cnt = 0;
        for0(i,n){
            if(nn[i] < min_m){
                cnt++;
            }
        }
        cout<<cnt<<" "<<0<<endl;
    }else if(min_m < min_n){
        // Yellow win
        int cnt = 0;
        for0(i,m){
            if(mm[i] < min_n){
                cnt++;
            }
        }
        cout<<0<<" "<<cnt<<endl;
    }
}

int main() {
    init_code();
    int t;
    cin>>t;
    for1(i,t){
        run_case(i);
    }
    return 0;
}