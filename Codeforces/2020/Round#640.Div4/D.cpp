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
        int n;
        cin>>n;
        int sum =0;
        vector<int>vec(n);
        for(int i =0 ; i<n; i++){
            cin>>vec[i];
            sum += vec[i];
        }
        int a =0;
        int b = 0;
        int temp = 0;
        int cnt = 0;
        if(vec.size() == 1){
            cout<<1<<" "<<vec[0]<<" "<<0<<endl;
        }
        else{
            while(vec.size() >0){
                if(vec.size() == n){
                    temp = vec[0];
                    vec.erase(vec.begin());
                    a += vec[0];
                    cnt++;
                    int tempb = 0;
                    while(tempb <= temp){
                        tempb += vec[vec.size() - 1];
                        vec.erase(vec.begin() +vec.size() - 1);
                        if(vec.size() == 0){
                            break;
                        }
                    }
                    temp = tempb;
                    b += tempb ;
                    cnt++;
                }else{
                    int tempa = 0;
                    while(tempa <= temp){
                        tempa += vec[0];
                        vec.erase(vec.begin());
                        if(vec.size() == 0){
                            break;
                        }
                    }
                    temp = tempa;
                    a += tempa;
                    cnt++;
                    if(vec.size() == 0){
                        break;
                    }

                    int tempb = 0;
                    while(tempb <= temp){
                        tempb += vec[vec.size() - 1];
                        vec.erase(vec.begin() +vec.size() - 1);
                        if(vec.size() == 0){

                            break;
                        }
                    }
                    temp = tempb;
                    b += tempb ;
                    cnt++;
                }
            }
            cout<<cnt<<" "<<sum - b<<" "<<b<<endl;
        }



	}


	return 0;
}
