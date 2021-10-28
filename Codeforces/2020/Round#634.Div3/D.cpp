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

int func(int n){
    int a = n+1;
    if(a%9 ==0 ){
        return 9;
    }
    else return a%9;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int a[9][9];
        int sum =0;
        for(int i = 0; i<9; i++){
            int s;
            cin>>s;

            for(int j =8;j>=0; j--){

                a[i][j] = s%10;
                s /= 10;
            }
        }
//        vector<int > vec(9);
//        vec.push_back(a[0][0]);
//        vec.push_back(a[3][1]);
//        vec.push_back(a[6][2]);
//        vec.push_back(a[1][3]);
//        vec.push_back(a[4][4]);
//        vec.push_back(a[7][5]);
//        vec.push_back(a[2][6]);
//        vec.push_back(a[5][7]);
//        vec.push_back(a[8][8]);

        a[0][0] = func(a[0][0] );
        a[3][1] = func(a[3][1]);
        a[6][2] =  func(a[6][2]);
        a[1][3] = func(a[1][3] );
        a[4][4] = func(a[4][4] );
        a[7][5] = func(a[7][5]);
        a[2][6] = func(a[2][6]);
        a[5][7] = func(a[5][7]);
        a[8][8] = func(a[8][8]);

        for(int i = 0; i<9; i++){
            for(int j =0 ; j<9; j++){
                cout<<a[i][j];
            }
            cout<<"\n";
        }

    }

    return 0;
}
