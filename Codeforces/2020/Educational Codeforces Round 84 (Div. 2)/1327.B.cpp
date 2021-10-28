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

void solve(){
    int n;//number of girls, and mens
    cin>>n;
    vector<int>checkBoy;
    vector<int>checkGirl;
    checkBoy.resize(n+1,-1);
    checkGirl.resize(n+1,-1);
    for(int i = 0; i<n; i++){
        int k;//number of checkBoy of gilrs i-th
        cin>>k;
        int count = 0;
        for(int j = 0; j<k;j++){
            int a;
            cin>>a;

            if(checkBoy[a] == -1 && count == 0){
                checkBoy[a] = 0;
                checkGirl[i+1] = 0;
                ++count;
            }
        }
    }

    vector<int>::iterator it1 = find(checkGirl.begin()+1, checkGirl.end(), -1);
    vector<int>::iterator it2 = find(checkBoy.begin()+1, checkBoy.end(), -1);
    if (it1 != checkGirl.end())
    {
        cout<<"IMPROVE"<<"\n";
        cout <<it1 - checkGirl.begin() <<" "<<it2 - checkBoy.begin()<<"\n";
    }
    else cout<<"OPTIMAL"<<"\n";
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;//NUMBER of cases
    while(t--){
         solve();
    }

	return 0;
}
