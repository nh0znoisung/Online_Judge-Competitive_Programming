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

const long long p = 1e9 + 7;
const int N = 2*1e5 + 1;
ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll Binomial(ll N, ll R, ll p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    if(N < R) return 0;
    ll ans = ((fact[N] * factorialNumInverse[R])% p * factorialNumInverse[N - R])% p;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);
 
    // 1st query
    ll N = 15;
    ll R = 4;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n);
        for(int i = 0; i<n ;i ++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        long long cnt = 0;
        for(int i = 0; i<n-m+1; i++){
            auto up1 = upper_bound(a.begin(), a.end(), a[i] + k);
           // cout<<"Helo"<<endl;
            int j = up1 - a.begin();
          //  cout<<j<<endl;
            // cout<<j-i-1<<endl;
            // cout<<m<<endl;
            // cout<<(long long)Binomial(j-i-1,m-1,p)<<endl;
            cnt += (long long)Binomial(j-i-1,m-1,p);
            cnt %= p;
          //  cout<<(long long)Binomial(j-i-1,m,p)<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}