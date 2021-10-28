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
	long long int n,k;
	cin>>n>>k;
	vector<long long int>vec(n+1);
	for(long long int i =0 ; i<n; i++){
        cin>>vec[i+1];
	}
	long long int cnt =0;
	vector<long long int>check(n+1);
	vector<long long int>con;
    long long int ptr =1;
//    cout<<ptr<<endl;
//    con.push_back(ptr);
//    for(int i =0 ; i<con.size();i++){
//        cout<<con[i]<<endl;
//	}
	while(check[ptr] == 0){
        cnt++;
        check[ptr] = 1;
        con.push_back(ptr);
        ptr = vec[ptr];

	}
	int cntt = 0;
	vector<long long int>chec(n+1);
	vector<long long int>cont;
    while(chec[ptr] == 0){
        cntt++;
        chec[ptr] = 1;
        cont.push_back(ptr);
        ptr = vec[ptr];

	}
//	cout<<cnt<<endl;
//	cout<<cntt<<endl;
//	for(int i =0 ; i<con.size();i++){
//        cout<<con[i]<<endl;
//	}
//	cout<<"afdghfj"<<endl;
//	for(int i =0 ;i<cont.size();i++){
//        cout<<cont[i]<<endl;
//	}
//	cout<<cntt<<endl;
    int l  =cnt -cntt;
    if(k<= l){
        cout<<con[k];
    }else{
        k -= (l);
        int d= k%cntt ;

        cout<<cont[d]<<endl;
    }





	return 0;
}
