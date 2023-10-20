#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

void init_code(){
    ios_base::sync_with_stdio(false);
    #ifndef NEAL_DEBUG
        cin.tie(0);
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
const int M=998244353;
const int N=3e5+1,E=524288;
ll n, arr[2*N+1];
//TODO: make sure all variables get reset
void run_case(int c){
    cin>>n;
    ll len = 2*n-1;
    ll total = 0;
    for (int i = 0; i < len; i++) {
        cin>>arr[i];
        total = total + arr[i] + 0ll;
    }
    if(n == 1){
        cout<< "Case #"<< c << ": " << 1 << endl; 
        return;
    }
    
    sort(arr, arr+len); // n*log(n)

    ll result = -1;
    for(int k = 0; k < len; k++) { // len
        // verify
        if( (total - arr[k]) % (n-1) != 0 ){
            continue;
        }
        ll target = (total - arr[k]) / (n-1);
        if(target <= arr[k]){
            continue;
        }


        // two-pointer
        int x = 0, y = len-1; //index
        bool ok = true;
        while(x < y){ // len
            if(k == x) x++;
            if(k == y) y--;

            if( (arr[x] + arr[y]) != target ){
                ok = false;
                break;
            }
            x++;
            y--;
        }

        // update result
        ll curr = target - arr[k];
        if(ok){
            if(result == -1) result = curr;
            else result = min(result, curr);
        }
    }

    // print result
    cout<< "Case #"<< c << ": " << result << endl; 
}


int main() {
    init_code();
    int t;
    cin>>t;
    for(int i = 1; i<=t; i++){
        run_case(i);
    }
    return 0;
}