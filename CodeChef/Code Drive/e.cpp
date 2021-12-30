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

// const int MAXN = 31630; //sqrt(1e9)
 
// // stores smallest prime factor for every number
// int spf[MAXN];
 

// void sieve()
// {
//     spf[1] = 1;
//     for (int i=2; i<MAXN; i++)
//         spf[i] = i;
//     for (int i=4; i<MAXN; i+=2)
//         spf[i] = 2;
 
//     for (int i=3; i*i<MAXN; i++)
//     {
//         if (spf[i] == i)
//         {
//             for (int j=i*i; j<MAXN; j+=i)
//                 if (spf[j]==j)
//                     spf[j] = i;
//         }
//     }
// }

 

int n;
//TODO: make sure all variables get reset
void run_case(){
	map<int, int> m;
	int mx = 0;

    int count = 0;
    while (!(n % 2)) {
        n >>= 1;
        count++;
    }
    m[2] = count;
	mx = max(mx, count);

    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count) {
			m[i] = count;
			mx = max(mx, count);
		}
    }
 
    if (n > 2) m[n] = 1;
	mx = max(mx, 1);

    
    for(auto it : m){
        if(it.second == mx){
			cout << it.first << endl;
			break;
		}
    }
}

int main() {
    init_code();
    int t;
    cin>>t;
	// sieve();
    while(t--){
		cin>>n;
    	run_case();
    }
    return 0;
}