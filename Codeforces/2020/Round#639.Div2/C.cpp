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

int Mod(int a, int n){
    if(a>0){
        return a%n;
    }else{
        return (n - (-a)%n)%n ;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i =0 ;i <n; i++){
            cin>>a[i];
        }
        bool res = 0;
        for(int i = 0 ; i<n;i++){
            int cnt = 0;
            for(int j = i+1; j<n ; j++){
                if(Mod(a[i]-a[j] , n) == Mod(j-i , n)){
                    res = true;
                    cnt++;
                    break;
                }
            }
            if(cnt >= 1){
                break;
            }
        }
        if(res){
            cout<<"NO"<<"\n";
        }else{
            cout<<"YES\n";
        }
	}

	return 0;
}
