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
        string s;
        cin>>s;
        int cnt = 0;
        int x = 0;
        int y =0;

        map<pair<pair<int,int>,pair<int,int>>, int> check;
//        check[{{1,2},{3,4}}] = 12345;
//        for(auto i :check){
//            cout<<i.second;
//        }
        for(int i =0 ; i<s.size();i++){
            if(s[i] == 'S'){
                if(check[{{x,y},{x,y-1}}] == 1){
                    cnt += 1;
                }else{
                    check[{{x,y},{x,y-1}}] = 1;
                    check[{{x,y-1},{x,y}}] = 1;
                    cnt += 5;
                }
                y -=1;
            }
            else if(s[i] == 'N'){
                if(check[{{x,y},{x,y+1}}] == 1){
                    cnt += 1;
                }else{
                    check[{{x,y},{x,y+1}}] = 1;
                    check[{{x,y+1},{x,y}}] = 1;
                    cnt += 5;
                }
                y += 1;
            }
            else if(s[i] == 'W'){
                if(check[{{x,y},{x-1,y}}] == 1){
                    cnt += 1;
                }else{
                    check[{{x,y},{x-1,y}}] = 1;
                    check[{{x-1,y},{x,y}}] = 1;
                    cnt += 5;
                }
                x -= 1;
            }
            else if(s[i] == 'E'){
                if(check[{{x,y},{x+1,y}}] == 1){
                    cnt += 1;
                }else{
                    check[{{x,y},{x+1,y}}] = 1;
                    check[{{x+1,y},{x,y}}] = 1;
                    cnt += 5;
                }
                x += 1;
            }


        }
        cout<<cnt<<endl;
	}


	return 0;
}
