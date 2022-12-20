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



void computeLPSArray(string pat, int& M, int& lps[])
{
	int len = 0;
	int i = 1;
	lps[0] = 0;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];
			}
			else
			{
				lps[i] = len;
				i++;
			}
		}
	}
}

int KMPSearch(string& pat, string& txt)
{
	int M = pat.length();
	int N = txt.length();

	int lps[M];
	int j = 0;
	computeLPSArray(pat, M, lps);

	int i = 0;
	int res = 0;
	int next_i = 0;

	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}
		if (j == M) {
			j = lps[j - 1];
			res++;
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
	return res;
}
bool check_suffix(string& s, string& txt){
    int M = s.length();
    int N = txt.length();
    
    int i = 0;
    for0(i,n){
        if(s[M-i-1] != txt[N-i-1]) return false;
    }
    return true;
}
string a[1e5+1]
// Driver code
int main()
{
	string s; cin>>s;
    int n = s.size();
    a[0] = "";
    for(int i = 1; i<= n; i++){
        a[i] = a[i-1] + s[i-1];
    }
    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        pat = a[x];
        if  (check_suffix(s, pat))  {
            int cnt = KMPSearch(pat, s);
            if( cnt > 3){
                cout << "YES "<< cnt << endl;
            }else cout<<"NO"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

	return 0;
}
