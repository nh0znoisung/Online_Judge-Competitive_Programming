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

const int n = 12;
int binatoint(string s){
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans *= 2;
        ans += (s[i] - '0');
    }
    return ans;
}

string oxygen(queue<string>q){
    int curr = 0;//pos of bit
    int cnt = 0;// 1
    while(q.size() != 1 && curr < n){
        int k = q.size();
        cnt = 0;
        // Find the most, keep 1
        while(k--){
            string s = q.front();
            q.pop();
            if(s[curr] == '1') cnt++;
            q.push(s);
        }
        char c = (cnt >= q.size() - cnt)?'1':'0';
        // Transform to new queue
        k = q.size();
        while(k--){
            string s = q.front();
            q.pop();
            if(s[curr] == c) q.push(s);
        }
        curr ++;
    }
    return q.front();
}

string co2(queue<string>q){
    int curr = 0;//pos of bit
    int cnt = 0;// 0
    while(q.size() != 1 && curr < n){
        int k = q.size();
        cnt = 0;
        // Find the least, keep 0
        while(k--){
            string s = q.front();
            q.pop();
            if(s[curr] == '0') cnt++;
            q.push(s);
        }
        char c = (cnt <= q.size() - cnt)?'0':'1';

        // Transform to new queue
        k = q.size();
        while(k--){
            string s = q.front();
            q.pop();
            if(s[curr] == c) q.push(s);
        }
        curr ++;
    }
    return q.front();
}

int main() {
    init_code();    
    string s;
    queue<string>q;
    while(cin>>s){
        q.push(s);
    }
    string a1 = oxygen(q);
    string b1 = co2(q);

    int a = binatoint(a1), b = binatoint(b1);

    cout<<(long long)a*b<<endl;   
    return 0;
}