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
        int sum1 = 1<<n;
        int sum2 = 1<<(n-1);
        int cnt1 = 1;
        int cnt2 = 1;

//        for(int i= n-2; i>=1; i--){
//            if(cnt1 == n/2){
//                sum2 += 1<<i;
//                cnt1++;
//            }
//            else if(cnt2 == n/2){
//                sum1 += 1<<i;
//                cnt2++;
//            }
//
//            else if(sum1 > sum2){
//                sum2 += 1<<i;
//
//                cnt2 ++;
////                if(cnt1<=n/2)
//            }
//            else if(sum2 > sum1){
//                sum1 += 1<<i;
//
//                cnt1 ++;
////                if(cnt1<=n/2)
//            }
////            cout<<sum1<<" "<<sum2<<"\n";
//        }
////        cout<<sum1<<" "<<sum2<<"\n";
//        cout<<abs(sum1-sum2)<<"\n";
        int sum =0;
        for(int i  =1; i<= n/2;i++ ){
            sum += (1<<i);
        }
        cout<<sum<<"\n";
    }



	return 0;
}
