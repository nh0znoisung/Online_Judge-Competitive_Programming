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

	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<ll> vec(n);
        for(int i =0; i<n; i++){
            cin>>vec[i];
        }
        ll maxi = -1e9;
        ll sign =0;
        ll res =0;

        for(ll i =0; i<n; i++){
            if(vec[i] < 0){
                if(sign == 0){
                    sign = -1;
                    maxi = vec[i];
                }
                else if(sign>0){
                    res += maxi;
                    maxi = vec[i];
                    sign =-1;
                }
                else if(sign <0){
                    maxi = max(maxi, vec[i]);
                }
            }
            else if(vec[i] > 0){
                if(sign == 0){
                    sign = 1;
                    maxi = vec[i];
                }
                else if(sign<0){
                    res += maxi;
                    maxi = vec[i];
                    sign = 1;
                }
                else if(sign >0){
                    maxi = max(maxi, vec[i]);
                }
            }
            if(i == n-1){
                res += maxi;
            }
//            cout<<maxi<<endl;
//            cout<<res<<endl;

        }
//        if(vec[n-1]*vec[n-2] <0){
//            res+= vec[n-1];
//        }



        cout<<res<<"\n";


	}
	return 0;




}
