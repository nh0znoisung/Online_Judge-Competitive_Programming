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
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i =0; i< n; i++){
        cin>>vec[i];
	}
	map<int,int>check;
	map<int,map<int, int>>a;
	vector<int>replay;
	replay = vec;
    for(int i =0; i< n; i++){
        for(int j = 2; j<= vec[i] ; j++){
            bool choose = true;
            for(int k = 2; k<=sqrt(j); k++){
                if(j % k == 0){
                    choose = false;
                    break;
                }
            }
            if(choose){
               while(replay[i] >1 && replay[i]%j == 0){
                    a[i][j] += 1;
                    check[j] = 1;
                    replay[i] /= j;
                }
            }
        }
	}
//	for(int i =0 ;i< n;i++){
//        for(auto j : check){
//            cout<<a[i][j.first]<<" ";
//        }
//        cout<<endl;
//	}
//	cout<<endl;
	//how many elemnent = 0 if >=2
	int res = 1;
	for(auto j : check){
       // i.first
//        int cnt = 0;
        int Min1 = 18;
        int Min2 = 18;
        for(int i=0; i< n;i ++){
            if(Min1 > a[i][j.first]){
                Min2 = Min1;
                Min1 = a[i][j.first];
            }
            else if(a[i][j.first] < Min2 && a[i][j.first] != Min1){
                Min2 = a[i][j.first];
            }
//            if(a[i][j.first] == 0){
//                cnt ++;
//            }
//            if(cnt >=2){
//                break;
//            }
        }
        int b = 0;
        for(int i=0; i< n;i ++){
            if(a[i][j.first] == Min1){
                b++;
            }
        }
        if(b>=2){
            Min2 = Min1;
        }
//        if(cnt >= 2){
//            check[j.first] = 0;
//        }
  //      check[j.first] = Min;

//        cout<<Min1 <<" "<<Min2<<endl;
        res *= pow(j.first,  Min2);
	}
	cout<<res<<endl;



	return 0;
}
