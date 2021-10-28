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
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>vec(n+1);
        for(int i = 1; i<= n ; i++){
            cin>>vec[i];
        }
        //check how many peak;
        map<int,int>check;
        int cnt = 0;
        int init = 0;
        for(int i = 2; i<n; i++){
            if(vec[i-1] < vec[i] && vec[i] > vec[i+1] ){
                check[i] = 1;
                cnt++;
                if(i<k){
                    init ++;
                }
            }
        }
//        for(auto j : check){
//            cout<<j.first<<endl;
//        }
//        cout<<init<<endl;

        int mini = init;
        int res = init;
        for(int i = 2; i+k-1<=n; i++){
            if(check[i] == 1){
                res -= 1;
            }
            if(check[i + k-2] == 1){
                res += 1;
            }
//            cout<<res<<endl;
            mini = max(res, mini);
        }
//        cout<<mini<<endl;
        int peak = mini + 1;
        int l;
        res = init;
        if(init == mini){
            l = 1;
        }
        else{
            for(int i = 2; i+k-1<=n; i++){
                if(check[i] == 1){
                    res -= 1;
                }
                if(check[i + k-2] == 1){
                    res += 1;
                }
                if(res == mini){
                    l = i;
                    break;
                }
            }
        }


        cout<<peak<<" "<<l<<"\n";
    }

	return 0;
}
