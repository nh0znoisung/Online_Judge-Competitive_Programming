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

int trans(string model, string s){
    int cnt = 0;
    for(int i =0; i<6; i++){
        if(s[0] == '1' && model[0] == '0'){
            return -1;
        }
        else if(s[0] == '0' && model[0] == '1'){
            cnt++;
        }
    }
    return cnt;
}

    //vec of string to int
int vectoint(vector<int> vec){
    int pow = 0;
    int sum = 0;
    for(int i= vec.size()-1; i>=0; i--){
        sum += vec[i] * pow(10, pow);
        pow++;
    }
    return sum;
}

int sovle(model[i] , vec[j]  ){
    if(i ==0){
        break;
    }
    if(vec[0] == ){
        break;
    }
    if(trans(model[i] , vec[j]) == -1){
        sovle(model[i-1] , vec[j]  )
    }else{
        solve(model[9], vec[j-1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;

	vector<string>vec(n);
	for(int i = 0; i<n; i++){
        cin>>vec[i];
	}
    vector<string> model(10);
	model[0] = "1110111";
	model[1] = "0010010";
	model[2] = "1011101";
	model[3] = "1011011";
	model[4] = "0111010";
	model[5] = "1101011";
	model[6] = "1101111";
	model[7] = "1010010";
	model[8] = "1111111";
	model[9] = "1111011";

    //string to int;
    map<string,int>check;
    for(int i = 0; i<10; i++){
        check[model[i]] = i;
    }
    adfssdfas = vec.size()-1 -> 0
    for(int i = 9;i>=0;i--){
        if(trans(model[i], vec[adfasdf]) == -1 ){
            continue;
        }
        else{

        }
    }







	return 0;
}
