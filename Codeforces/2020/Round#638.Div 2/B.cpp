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
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>vec(n);
        vector<int>rep;

        vector<int>ya(n+1);
        vector<int>visited(n+1);
        map<int,int>cou;

        map<int,int> check;
//        map<int,bool>lol;
        for(int i =0; i<n;i++){
            cin>>vec[i];
            check[vec[i]] += 1;
//            lol[vec[i]] =1;
            ya[vec[i]] = 1;
        }
        int cnt = 0;

        for(auto i : check){
            cnt ++;

        }
//        cout<<cnt<<endl;
        if(cnt> k){
            cout<<-1<<"\n";
        }else{
            for(int i= 0;i<n; i++){
                rep.push_back(vec[i]);
                visited[rep[i]] = 1;
                cou[rep[i]] += 1;

                if(visited == ya){
                    break;
                }
            }
            rep.resize(k,1);
//            for(int i = 0; i<rep.size();i++){
//                cout<<rep[i]<<" ";
//            }
//            cout<<endl;


            int coun = 9999;
//            while(vec.size()>0){
//                for(int j = 0; j<rep.size(); j++){
//                    if(vec.size() == 0){
//                        break;
//                    }else{
//                        coun ++;
//                        if(rep[j] == vec[0]){
//                            vec.erase(vec.begin());
//                        }
//                    }
//
//
//
//                }
//
//            }
            cout<<coun<<endl;

            for(int i = 0; i< coun; i++){
                cout<<rep[i%rep.size()]<<" ";
            }
            cout<<endl;


        }



	}


	return 0;
}
