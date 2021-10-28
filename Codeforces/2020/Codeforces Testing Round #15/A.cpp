#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k;
	cin>>k;
	int n =1;//number of digits
	ll sum = 0;
	for(int i = 0; i<=12; i++){
        sum += 9*pow(10,n-1)*n;
        if(sum >= k){
            break;
        }
        n++;
	}


	sum -= 9*pow(10,n-1)*n;
	n--;
	//cout<<n<<endl;
	//cout<<sum<<endl;

	ll c = pow(10, n) + (k - sum-1) / (n+1);
   // cout<<a<<endzl;
   // cout<<b<<endl;
   // cout<<c<<endl;


    string str = to_string(c);
   // cout<<str[1];

    ll d = (k - sum) % (n+1);
    if(d == 0) d = n+1;
    cout<<str[d-1];




	return 0;
}
