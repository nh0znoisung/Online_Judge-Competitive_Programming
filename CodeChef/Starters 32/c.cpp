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
const int N=100005,E=524288;


int n, k, a[N];
//TODO: make sure all variables get reset
void run_case(){
    cin>>n>>k;
    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    priority_queue<pair<int,int>> pq;
    int mx = -1, mn = (int) 1e5+5;
    for0(i,n){
        cin>>a[i];
        pq.push({a[i],i});
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if(k > n-1){
        cout<<mx<<endl;
        return;
    }
    if(k == 0){
        cout<<mn<<endl;
        return;
    }
    int id1 = -1, id2 = -1;
    bool flag=  false;
    for0(i,n){
        if(a[i] == mn){
            if(!flag){
                id1 = i;
                flag = true;
            }else id2 = i;
        }
    }
    // id2 > id1, id differ id1, id2
    while(!pq.empty()){
        int id = pq.top().se, x = pq.top().first, count = 0;

        if(id2 == -1){
            count = abs(id - id1);
        }else{
            if(id < id1){   
                count = abs(id - id2);
            }else if(id > id2){
                count = abs(id - id1);
            }else{
                count = abs(id - id1) + abs(id-id2);
            }
        }
        if(count <= k){
            if(id2 == -1){
                for(int i = min(id1,id); i <= max(id1,id); i++){
                    a[i] = x;
                }
            }else{
                if(id < id1){   
                    for(int i = id; i <= id2; i++) a[i] = x;
                    
                }else if(id > id2){
                    for(int i = id1; i <= id; i++) a[i] = x;
                }else{
                    for(int i = id1; i <= id2; i++) a[i] = x;
                }
            }

            mn = (int)1e5 + 5;
            for0(i,n){
                if(a[i] < mn) mn = a[i];
            }
            cout<<mn<<endl;
            return;
        }
        pq.pop();
    }
    cout<<mn<<endl;
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