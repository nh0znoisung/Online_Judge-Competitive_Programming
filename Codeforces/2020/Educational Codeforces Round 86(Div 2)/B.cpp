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
        string s;
        cin>>s;
        string l;
        string res;
        l = s;
        int cnt1 = 0;
        int cnt0 = 0;
        int cnt3 =0;
        int cnt4 =0 ;
        for(int i =0 ; i<s.size(); i++){
            if(s[i] == '1'){
                cnt1++;
            }else{
                cnt0 ++;
            }
        }
        if(cnt1 == s.size() || cnt0 == s.size()){
            cout<<s<<endl;
        }else{
            int cnt = s.size();
            while(cnt --){
                res.push_back('0');
                res.push_back('1');
            }
            cout<<res<<endl;
//            //call 10
//            l =s;
//            while(l.size() >0){
//                if(l[0] == '1' && l[1] == '0'){
//                    l.erase(0);
//                    l.erase(0);
//                    cnt3++;
//                }
//                else{
//                    l.erase(0);
//
//                }
//            }
//            //call 01
//            l = s;
//            while(l.size() >0){
//                if(l[0] == '0' && l[1] == '1'){
//                    l.erase(0);
//                    l.erase(0);
//                    cnt4++;
//                }
//                else{
//                    l.erase(0);
//
//                }
//            }
//            cout<<cnt3<<endl;
//            cout<<cnt4<<endl;
//            if(cnt3 > cnt4){
//                cout<<"dafdsgd"<<endl;
//                int as = s.size() - cnt3 +1;
//                while(as--){
//                    res.push_back('1');
//                    res.push_back('0');
//                }
//            }else{
//                cout<<"adsfghdfs"<<endl;
//                int as = s.size() - cnt4 +1;
//                while(as--){
//                    res.push_back('0');
//                    res.push_back('1');
//                }
//            }
//            cout<<res<<endl;

        }

	}
	return 0;
}
