#include <bits/stdc++.h>
#include <iostream>
using namespace std;
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
const int N=1000005,E=524288;
int s,d,k;
//TODO: make sure all variables get reset
void run_case(int c){
    cin>>s>>d>>k;

    int a = 2*s + 2 * d; // bread
    int b = s + 2*d; // meat

    // k-decker -> k+1 bread, k meat
    cout<< "Case #"<< c << ": ";
    if(a >= k+1 && b >= k){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
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

