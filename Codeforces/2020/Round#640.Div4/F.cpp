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
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n0, n1,n2;
        cin>>n0>>n1>>n2;
        string s;
        if(n1 == 0){
            if(n0 != 0){
                for(int i =0 ; i<n0+1; i++){
                    cout<<0;
                }
            }
            if(n2 != 0){
                for(int i =0 ; i< n2+1; i++){
                    cout<<1;
                }

            }
            cout<<endl;
        }else{
            if(n1 % 2 != 0){
                for(int i=0; i<n0+1; i++){
                    cout<<0;
                }
                for(int i= 0; i<n1/2; i++){
                    cout<<"10";

                }
                cout<<"1";
                for(int i=0; i<n2; i++){
                    cout<<"1";
                }
            }else{
                cout<<"10";
                for(int i=0; i<n0; i++){
                    cout<<0;
                }
                for(int i= 0; i<n1/2-1; i++){
                    cout<<"10";

                }
                cout<<"1";
                for(int i=0; i<n2; i++){
                    cout<<"1";
                }
            }


            cout<<endl;
        }

	}


	return 0;
}
