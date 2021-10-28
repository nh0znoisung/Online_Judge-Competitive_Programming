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
        string s;
        cin>>s;
        vector<int>arr(3);
        for(int i = 0; i<s.size();i++ ){
            if(s[i] == '1'){
                arr[0] += 1;
            }else if(s[i] == '2'){
                arr[1] += 1;
            }
            else if(s[i] == '3'){
                arr[2] += 1;
            }
        }
     //   cout<<arr[0]<<arr[1]<<arr[2]<<endl;
        if(arr[0] == 0 ||arr[1] == 0 ||arr[2] == 0){
            cout<<0<<endl;
        }else{
            int ans = s.size();
            for(int i = 0; i< s.size() -2;i++){
                if(s[i+1] == s[i]){
                    continue;
                }else{
                   // cout<<"sadfg"<<endl;
                    int cnt = 2;
                    bool tick = 0;
                    for(int j = i+2; j<s.size();j++){
                        cnt++;
                       // cout<<s[j]<<s[i]<<s[i+1]<<endl;
                      //  cout<<cnt<<endl;
                        if(s[j] != s[i] && s[j] != s[i+1]){
                            tick = true;
                            break;
                        }
                    //    cout<<i<<endl;
                    }
                    if(tick){
                        ans = min(ans,cnt);
                    }

                }


            }
            cout<<ans<<endl;
        }
	}


	return 0;
}
